from __future__ import annotations

from collections import Counter
from datetime import datetime, timezone
from pathlib import Path

from .charts import write_charts
from .config import (
    ASSETS_DIR,
    DIFFICULTY_DIR,
    DIFFICULTY_ORDER,
    LANGUAGES_DIR,
    MEMORY_DIR,
    PAGE_SLUGS,
    PROFILE_URL,
    README_PATH,
    RECENT_LIMIT,
    ROOT,
    RUNTIME_DIR,
    SITE_TITLE,
    STATS_CARD_URL,
    TAIPEI_TZ,
    TOPICS_DIR,
    TOPICS_LINK_COLUMNS,
)
from .problems import (
    filter_by_percentile,
    lang_label,
    memory_percentile_buckets,
    percentile_pages,
    runtime_percentile_buckets,
)
from .text import md_escape


def write_readme(problems: list[dict]) -> None:
    difficulties = Counter(p.get("difficulty") or "Unknown" for p in problems)
    languages = Counter(lang_label(p.get("lang")) for p in problems)
    generated_at = datetime.now(TAIPEI_TZ).strftime("%Y-%m-%d %H:%M UTC+8")

    difficulty_pages = [
        (name, page_slug(name), count)
        for name in (*DIFFICULTY_ORDER, "Unknown")
        if (count := difficulties.get(name, 0))
    ]
    language_pages = [
        (name, page_slug(name), count) for name, count in languages.most_common()
    ]
    runtime_stat_pages = percentile_pages(problems, "runtimePercentile", "runtime")
    memory_stat_pages = percentile_pages(problems, "memoryPercentile", "memory")
    topic_pages = [
        (name, page_slug(name), count)
        for name, count in Counter(
            topic
            for problem in problems
            for topic in (problem.get("topics") or [])
            if topic
        ).most_common()
    ]

    write_page(
        problems,
        title=SITE_TITLE,
        dest=README_PATH,
        assets_dir=ASSETS_DIR,
        asset_rel="assets",
        generated_at=generated_at,
        include_card=True,
        difficulty_links=nav_links(difficulty_pages, prefix="stats/difficulty/"),
        language_links=nav_links(language_pages, prefix="stats/languages/"),
        runtime_links=nav_links(runtime_stat_pages, prefix="stats/runtime/"),
        memory_links=nav_links(memory_stat_pages, prefix="stats/memory/"),
        topic_links=nav_topic_links(topic_pages, prefix="stats/topics/"),
    )

    for name, slug, _count in difficulty_pages:
        filtered = [
            problem
            for problem in problems
            if (problem.get("difficulty") or "Unknown") == name
        ]
        write_page(
            filtered,
            title=f"{name} Stats",
            dest=DIFFICULTY_DIR / f"{slug}.md",
            assets_dir=ASSETS_DIR / "difficulty" / slug,
            asset_rel=f"../../assets/difficulty/{slug}",
            generated_at=generated_at,
            back_link="[All stats](../../README.md)",
            difficulty_links=nav_links(difficulty_pages, current=slug),
        )

    for name, slug, _count in language_pages:
        filtered = [problem for problem in problems if lang_label(problem.get("lang")) == name]
        write_page(
            filtered,
            title=f"{name} Stats",
            dest=LANGUAGES_DIR / f"{slug}.md",
            assets_dir=ASSETS_DIR / "languages" / slug,
            asset_rel=f"../../assets/languages/{slug}",
            generated_at=generated_at,
            back_link="[All stats](../../README.md)",
            language_links=nav_links(language_pages, current=slug),
        )

    extra_pages = 0
    for label, slug, _count in runtime_stat_pages:
        filtered = filter_by_percentile(
            problems, "runtimePercentile", int(label.split("-")[0]) // 10
        )
        write_page(
            filtered,
            title=f"Runtime {label}% Stats",
            dest=RUNTIME_DIR / f"{slug}.md",
            assets_dir=ASSETS_DIR / "runtime" / slug,
            asset_rel=f"../../assets/runtime/{slug}",
            generated_at=generated_at,
            back_link="[All stats](../../README.md)",
            runtime_links=nav_links(runtime_stat_pages, current=slug),
        )
        extra_pages += 1

    for label, slug, _count in memory_stat_pages:
        filtered = filter_by_percentile(
            problems, "memoryPercentile", int(label.split("-")[0]) // 10
        )
        write_page(
            filtered,
            title=f"Memory {label}% Stats",
            dest=MEMORY_DIR / f"{slug}.md",
            assets_dir=ASSETS_DIR / "memory" / slug,
            asset_rel=f"../../assets/memory/{slug}",
            generated_at=generated_at,
            back_link="[All stats](../../README.md)",
            memory_links=nav_links(memory_stat_pages, current=slug),
        )
        extra_pages += 1

    for name, slug, _count in topic_pages:
        filtered = [
            problem for problem in problems if name in (problem.get("topics") or [])
        ]
        write_page(
            filtered,
            title=f"{name} Stats",
            dest=TOPICS_DIR / f"{slug}.md",
            assets_dir=ASSETS_DIR / "topics" / slug,
            asset_rel=f"../../assets/topics/{slug}",
            generated_at=generated_at,
            back_link="[All stats](../../README.md)",
            topic_links=nav_topic_links(topic_pages, current=slug),
        )
        extra_pages += 1

    print(
        f"Wrote {README_PATH.relative_to(ROOT)} and "
        f"{len(difficulty_pages) + len(language_pages) + extra_pages} stat pages "
        f"({len(problems)} problems)"
    )


def write_page(
    problems: list[dict],
    *,
    title: str,
    dest: Path,
    assets_dir: Path,
    asset_rel: str,
    generated_at: str,
    include_card: bool = False,
    back_link: str | None = None,
    difficulty_links: str = "",
    language_links: str = "",
    runtime_links: str = "",
    memory_links: str = "",
    topic_links: str = "",
    show_difficulty: bool = True,
) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    dest.write_text(
        build_page(
            problems,
            title=title,
            asset_rel=asset_rel,
            generated_at=generated_at,
            include_card=include_card,
            back_link=back_link,
            difficulty_links=difficulty_links,
            language_links=language_links,
            runtime_links=runtime_links,
            memory_links=memory_links,
            topic_links=topic_links,
            assets_dir=assets_dir,
            show_difficulty=show_difficulty,
        ),
        encoding="utf-8",
        newline="\n",
    )


def build_page(
    problems: list[dict],
    *,
    title: str,
    asset_rel: str,
    generated_at: str,
    include_card: bool,
    back_link: str | None,
    difficulty_links: str,
    language_links: str,
    runtime_links: str,
    memory_links: str,
    topic_links: str,
    assets_dir: Path,
    show_difficulty: bool = True,
) -> str:
    difficulties = Counter(p.get("difficulty") or "Unknown" for p in problems)
    languages = Counter(lang_label(p.get("lang")) for p in problems)
    topics = Counter(
        topic
        for problem in problems
        for topic in (problem.get("topics") or [])
        if topic
    )
    runtime_buckets = runtime_percentile_buckets(problems)
    memory_buckets = memory_percentile_buckets(problems)
    write_charts(
        difficulties,
        languages,
        topics,
        runtime_buckets,
        memory_buckets,
        output_dir=assets_dir,
        include_difficulty=show_difficulty,
    )

    lines = [f"# {title}", ""]
    if include_card:
        lines += [
            f"[![LeetCode Stats]({STATS_CARD_URL})]({PROFILE_URL})",
            "",
            "Accepted solutions synced from LeetCode.",
            "",
        ]
    if back_link:
        lines += [back_link, ""]
    lines += [
        f"**{len(problems)}** problems · updated `{generated_at}`",
        "",
        "## Stats",
        "",
    ]
    if show_difficulty:
        add_chart_section(lines, "Difficulty", f"{asset_rel}/difficulty.svg", difficulty_links)
    add_chart_section(lines, "Language", f"{asset_rel}/language.svg", language_links)
    add_chart_section(
        lines, "Runtime Percentile", f"{asset_rel}/runtime.svg", runtime_links
    )
    add_chart_section(
        lines, "Memory Percentile", f"{asset_rel}/memory.svg", memory_links
    )
    if topics:
        add_chart_section(lines, "Topics", f"{asset_rel}/topics.svg", topic_links)

    recent = recent_accepted(problems, RECENT_LIMIT)
    if recent:
        lines += [
            "---",
            "",
            "## Recent Activity",
            "",
            f"Latest **{len(recent)}** accepted submissions.",
            "",
            "| Date | Title | Difficulty | Lang | Runtime | Memory |",
            "| :--- | :--- | :---: | :---: | ---: | ---: |",
        ]
        lines.extend(activity_row(problem) for problem in recent)
    lines.append("")
    return "\n".join(lines)


def add_chart_section(
    lines: list[str], heading: str, image: str, links: str = ""
) -> None:
    lines += [f"### {heading}", "", f"![{heading}]({image})", ""]
    if links:
        lines += [links, ""]


def page_slug(label: str) -> str:
    if label in PAGE_SLUGS:
        return PAGE_SLUGS[label]
    slug = "".join(ch.lower() if ch.isalnum() else "-" for ch in label)
    return "-".join(part for part in slug.split("-") if part)


def nav_links(
    pages: list[tuple[str, str, int]],
    prefix: str = "",
    current: str | None = None,
) -> str:
    if not pages:
        return ""
    headers = []
    cells = []
    for name, slug, count in pages:
        href = f"{prefix}{slug}.md"
        if slug == current:
            headers.append(f"**{name}**")
            cells.append(f"**{count}**")
        else:
            headers.append(f"[{name}]({href})")
            cells.append(str(count))
    return "\n".join(
        [
            "| " + " | ".join(headers) + " |",
            "| " + " | ".join(":---:" for _ in pages) + " |",
            "| " + " | ".join(cells) + " |",
        ]
    )


def nav_topic_links(
    pages: list[tuple[str, str, int]],
    prefix: str = "",
    current: str | None = None,
    columns: int = TOPICS_LINK_COLUMNS,
) -> str:
    if not pages:
        return ""
    columns = max(1, min(columns, len(pages)))
    height = (len(pages) + columns - 1) // columns
    header = " | ".join(["Topic", "#"] * columns)
    align = " | ".join([":---", "---:"] * columns)
    rows = [f"| {header} |", f"| {align} |"]
    for row in range(height):
        cells = []
        for column in range(columns):
            index = column * height + row
            if index < len(pages):
                name, slug, count = pages[index]
                href = f"{prefix}{slug}.md"
                if slug == current:
                    cells.extend([f"**{name}**", f"**{count}**"])
                else:
                    cells.extend([f"[{name}]({href})", str(count)])
            else:
                cells.extend(["", ""])
        rows.append("| " + " | ".join(cells) + " |")
    return "\n".join(rows)


def recent_accepted(problems: list[dict], limit: int) -> list[dict]:
    accepted = [
        problem
        for problem in problems
        if (problem.get("status") or "Accepted") == "Accepted"
    ]
    accepted.sort(key=submitted_at, reverse=True)
    return accepted[:limit]


def submitted_at(problem: dict) -> str:
    return problem.get("submittedAt") or ""


def format_date(raw: str | None) -> str:
    if not raw:
        return "-"
    try:
        parsed = datetime.fromisoformat(raw.replace("Z", "+00:00"))
        if parsed.tzinfo is None:
            parsed = parsed.replace(tzinfo=timezone.utc)
        text = parsed.astimezone(TAIPEI_TZ).strftime("%Y-%m-%d")
    except ValueError:
        text = raw[:10]
    # Keep YYYY-MM-DD on one line; GitHub tables wrap at ASCII hyphens.
    return text.replace("-", "&#8209;")


def activity_row(problem: dict) -> str:
    number = problem.get("id") or problem["_id"]
    title = md_escape(problem.get("title") or problem["_folder"])
    label = f"{number}. {title}"
    slug = problem.get("titleSlug")
    folder = problem["_folder"]
    if slug:
        title_link = f"[{label}](https://leetcode.com/problems/{slug}/)"
    else:
        title_link = f"[{label}](leetcode/{folder}/)"
    difficulty = md_escape(problem.get("difficulty") or "Unknown")
    language = lang_label(problem.get("lang"))
    runtime = format_metric(problem.get("runtime"), problem.get("runtimePercentile"))
    memory = format_metric(problem.get("memory"), problem.get("memoryPercentile"))
    date = format_date(problem.get("submittedAt"))
    return (
        f"| {date} | {title_link} | {difficulty} "
        f"| {language} | {runtime} | {memory} |"
    )


def format_metric(value, percentile) -> str:
    text = md_escape(str(value or "-"))
    if not percentile:
        return text
    percent = md_escape(str(percentile).strip())
    if not percent.endswith("%"):
        percent = f"{percent}%"
    return f"{text}<br>`{percent}`"
