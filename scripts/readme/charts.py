from __future__ import annotations

from collections import Counter
from math import cos, radians, sin
from pathlib import Path

from .config import (
    ASSETS_DIR,
    CHART_BG,
    CHART_BORDER,
    CHART_FONT,
    CHART_MONO,
    CHART_MUTED,
    CHART_PALETTE,
    CHART_SURFACE,
    CHART_TEXT,
    CHART_TRACK,
    DIFFICULTY_COLORS,
    DIFFICULTY_ORDER,
    TOPICS_CHART_LIMIT,
)
from .text import xml_escape


def write_charts(
    difficulties: Counter,
    languages: Counter,
    topics: Counter,
    runtime_buckets: list[tuple[str, int]] | None = None,
    memory_buckets: list[tuple[str, int]] | None = None,
    output_dir: Path | None = None,
    include_difficulty: bool = True,
) -> None:
    output_dir = output_dir or ASSETS_DIR
    output_dir.mkdir(parents=True, exist_ok=True)
    if include_difficulty:
        difficulty_items = [
            (name, difficulties.get(name, 0))
            for name in DIFFICULTY_ORDER
            if difficulties.get(name, 0)
        ]
        if difficulties.get("Unknown"):
            difficulty_items.append(("Unknown", difficulties["Unknown"]))
        svg_donut(
            "Difficulty",
            difficulty_items,
            [DIFFICULTY_COLORS[name] for name, _ in difficulty_items],
            output_dir / "difficulty.svg",
        )
    svg_donut(
        "Language",
        list(languages.most_common()),
        list(CHART_PALETTE),
        output_dir / "language.svg",
    )
    topic_items = list(topics.most_common())
    svg_bars(
        "Topics",
        topic_items[:TOPICS_CHART_LIMIT],
        output_dir / "topics.svg",
        subtitle=f"top {min(TOPICS_CHART_LIMIT, len(topic_items))} · {len(topic_items)} tags",
    )
    if runtime_buckets:
        sampled = sum(count for _, count in runtime_buckets)
        svg_histogram(
            "Runtime Percentile",
            runtime_buckets,
            output_dir / "runtime.svg",
            subtitle=f"{sampled} submissions",
        )
    if memory_buckets:
        sampled = sum(count for _, count in memory_buckets)
        svg_histogram(
            "Memory Percentile",
            memory_buckets,
            output_dir / "memory.svg",
            subtitle=f"{sampled} submissions",
        )


def svg_donut(
    title: str,
    items: list[tuple[str, int]],
    colors: list[str],
    path: Path,
) -> None:
    slices = [(name, count) for name, count in items if count > 0]
    width = 560
    legend_y = 78
    outer, inner = 98, 62
    header_bottom = 58
    legend_h = max(len(slices), 1) * 52
    min_cy = header_bottom + outer + 10
    cy = max(min_cy, legend_y + legend_h / 2)
    height = max(300, int(cy + outer + 24), legend_y + legend_h + 28)
    cx = 150
    total = sum(count for _, count in slices) or 1

    parts = _card_open(title, width, height, f"{total} solved", extra_defs=_glow_filter())

    if len(slices) == 1:
        color = colors[0]
        parts.append(
            f'<circle cx="{cx}" cy="{cy}" r="{(outer + inner) / 2:.1f}" '
            f'fill="none" stroke="{color}" stroke-width="{outer - inner}" filter="url(#glow)"/>'
        )
    elif slices:
        angle = -90.0
        gap = 3.2 if len(slices) > 1 else 0.0
        for index, (_, count) in enumerate(slices):
            sweep = 360.0 * count / total
            usable = max(sweep - gap, 0.4)
            start = angle + gap / 2
            end = start + usable
            color = colors[index % len(colors)]
            parts.append(
                f'<path d="{_donut_path(cx, cy, outer, inner, start, end)}" '
                f'fill="{color}" filter="url(#glow)"/>'
            )
            angle += sweep

    parts.append(f'<circle cx="{cx}" cy="{cy}" r="{inner - 2}" fill="{CHART_BG}"/>')
    parts.append(
        f'<text x="{cx}" y="{cy - 4}" fill="{CHART_TEXT}" font-size="28" font-weight="700" '
        f'font-family="{CHART_MONO}" text-anchor="middle">{total}</text>'
    )
    parts.append(
        f'<text x="{cx}" y="{cy + 18}" fill="{CHART_MUTED}" font-size="11" '
        f'font-family="{CHART_FONT}" text-anchor="middle">solved</text>'
    )

    legend_x = 292
    for index, (name, count) in enumerate(slices):
        y = legend_y + index * 52
        color = colors[index % len(colors)]
        percent = 100.0 * count / total
        parts.append(
            f'<rect x="{legend_x}" y="{y}" width="236" height="44" rx="12" fill="{CHART_SURFACE}" stroke="{CHART_BORDER}"/>'
        )
        parts.append(f'<rect x="{legend_x + 14}" y="{y + 16}" width="12" height="12" rx="4" fill="{color}"/>')
        parts.append(
            f'<text x="{legend_x + 36}" y="{y + 20}" fill="{CHART_TEXT}" font-size="14" font-weight="600" '
            f'font-family="{CHART_FONT}">{xml_escape(name)}</text>'
        )
        parts.append(
            f'<text x="{legend_x + 36}" y="{y + 35}" fill="{CHART_MUTED}" font-size="12" '
            f'font-family="{CHART_MONO}">{count}  ·  {percent:.0f}%</text>'
        )

    parts.append("</svg>")
    path.write_text("\n".join(parts) + "\n", encoding="utf-8", newline="\n")


def svg_bars(
    title: str,
    items: list[tuple[str, int]],
    path: Path,
    subtitle: str | None = None,
) -> None:
    rows = [(name, count) for name, count in items if count > 0]
    if not rows:
        return

    row_h, top, left, right, bottom = 34, 68, 236, 28, 24
    width = 840
    height = top + bottom + row_h * len(rows)
    max_count = max(count for _, count in rows)
    bar_max = width - left - right - 56

    parts = _card_open(title, width, height, subtitle or f"{len(rows)} tags")
    for index, (name, count) in enumerate(rows):
        y = top + index * row_h
        bar_w = 0 if max_count == 0 else bar_max * count / max_count
        color = CHART_PALETTE[index % len(CHART_PALETTE)]
        if index % 2 == 0:
            parts.append(
                f'<rect x="16" y="{y - 10}" width="{width - 32}" height="{row_h - 2}" rx="10" fill="{CHART_SURFACE}"/>'
            )
        parts.append(
            f'<text x="36" y="{y + 12}" fill="{CHART_MUTED}" font-size="11" '
            f'font-family="{CHART_MONO}">{index + 1:02d}</text>'
        )
        parts.append(
            f'<text x="{left - 16}" y="{y + 13}" fill="{CHART_TEXT}" font-size="13" '
            f'font-family="{CHART_FONT}" text-anchor="end">{xml_escape(name)}</text>'
        )
        parts.append(
            f'<rect x="{left}" y="{y + 3}" width="{bar_max}" height="12" rx="6" fill="{CHART_TRACK}"/>'
        )
        parts.append(
            f'<rect x="{left}" y="{y + 3}" width="{max(bar_w, 8):.1f}" height="12" rx="6" fill="{color}"/>'
        )
        parts.append(
            f'<text x="{left + bar_max + 12}" y="{y + 14}" fill="{CHART_TEXT}" font-size="13" '
            f'font-family="{CHART_MONO}">{count}</text>'
        )
    parts.append("</svg>")
    path.write_text("\n".join(parts) + "\n", encoding="utf-8", newline="\n")


def svg_histogram(
    title: str,
    items: list[tuple[str, int]],
    path: Path,
    subtitle: str | None = None,
) -> None:
    rows = list(items)
    if not rows:
        return

    width, height = 840, 320
    left, right, top, bottom = 48, 28, 72, 48
    chart_w = width - left - right
    chart_h = height - top - bottom
    gap = 10
    bar_w = (chart_w - gap * (len(rows) + 1)) / len(rows)
    total = sum(count for _, count in rows) or 1
    max_count = max(count for _, count in rows) or 1

    parts = _card_open(title, width, height, subtitle or f"{total} submissions")
    parts.append(
        f'<line x1="{left}" y1="{top + chart_h}" x2="{left + chart_w}" y2="{top + chart_h}" '
        f'stroke="{CHART_BORDER}" stroke-width="1"/>'
    )

    for index, (name, count) in enumerate(rows):
        x = left + gap + index * (bar_w + gap)
        bar_h = 0 if max_count == 0 else chart_h * count / max_count
        y = top + chart_h - bar_h
        color = CHART_PALETTE[index % len(CHART_PALETTE)]
        percent = 100.0 * count / total
        parts.append(
            f'<rect x="{x:.1f}" y="{y:.1f}" width="{bar_w:.1f}" height="{max(bar_h, 2):.1f}" '
            f'rx="8" fill="{color}"/>'
        )
        parts.append(
            f'<text x="{x + bar_w / 2:.1f}" y="{y - 8:.1f}" fill="{CHART_TEXT}" font-size="12" '
            f'font-family="{CHART_MONO}" text-anchor="middle">{percent:.0f}%</text>'
        )
        parts.append(
            f'<text x="{x + bar_w / 2:.1f}" y="{top + chart_h + 18}" fill="{CHART_MUTED}" font-size="11" '
            f'font-family="{CHART_MONO}" text-anchor="middle">{xml_escape(name)}</text>'
        )

    parts.append("</svg>")
    path.write_text("\n".join(parts) + "\n", encoding="utf-8", newline="\n")


def _card_open(
    title: str,
    width: int,
    height: int,
    subtitle: str,
    extra_defs: str = "",
) -> list[str]:
    return [
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{width}" height="{height}" viewBox="0 0 {width} {height}" role="img" aria-label="{xml_escape(title)}">',
        "<defs>",
        f'<linearGradient id="titleBar" x1="0" y1="0" x2="1" y2="0">'
        f'<stop offset="0%" stop-color="#fab387"/><stop offset="50%" stop-color="#cba6f7"/>'
        f'<stop offset="100%" stop-color="#89b4fa"/></linearGradient>',
        extra_defs,
        "</defs>",
        f'<rect width="100%" height="100%" rx="18" fill="{CHART_BG}" stroke="{CHART_BORDER}" stroke-width="1"/>',
        f'<rect x="20" y="18" width="4" height="22" rx="2" fill="url(#titleBar)"/>',
        f'<text x="34" y="36" fill="{CHART_TEXT}" font-size="18" font-weight="700" font-family="{CHART_FONT}">{xml_escape(title)}</text>',
        f'<text x="{width - 24}" y="36" fill="{CHART_MUTED}" font-size="12" font-family="{CHART_MONO}" text-anchor="end">{xml_escape(subtitle)}</text>',
    ]


def _glow_filter() -> str:
    return (
        '<filter id="glow" x="-20%" y="-20%" width="140%" height="140%">'
        '<feGaussianBlur stdDeviation="1.2" result="blur"/>'
        '<feMerge><feMergeNode in="blur"/><feMergeNode in="SourceGraphic"/></feMerge>'
        "</filter>"
    )


def _donut_path(
    cx: float,
    cy: float,
    outer: float,
    inner: float,
    start: float,
    end: float,
) -> str:
    large = 1 if (end - start) > 180 else 0
    osx, osy = _polar(cx, cy, outer, start)
    oex, oey = _polar(cx, cy, outer, end)
    isx, isy = _polar(cx, cy, inner, start)
    iex, iey = _polar(cx, cy, inner, end)
    return (
        f"M {osx:.2f} {osy:.2f} "
        f"A {outer} {outer} 0 {large} 1 {oex:.2f} {oey:.2f} "
        f"L {iex:.2f} {iey:.2f} "
        f"A {inner} {inner} 0 {large} 0 {isx:.2f} {isy:.2f} Z"
    )


def _polar(cx: float, cy: float, radius: float, angle_deg: float) -> tuple[float, float]:
    angle = radians(angle_deg)
    return cx + radius * cos(angle), cy + radius * sin(angle)
