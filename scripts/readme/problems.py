from __future__ import annotations

import json

from .config import LANG_LABELS, LEETCODE_DIR


def load_problems() -> list[dict]:
    problems = []
    if not LEETCODE_DIR.is_dir():
        return problems

    for status_path in sorted(LEETCODE_DIR.glob("*/status.json")):
        try:
            data = json.loads(status_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue

        folder = status_path.parent.name
        data["_folder"] = folder
        data["_id"] = parse_id(data.get("id"), folder)
        problems.append(data)

    problems.sort(key=lambda item: item["_id"])
    return problems


def parse_id(raw_id, folder: str) -> int:
    if raw_id is not None:
        try:
            return int(raw_id)
        except (TypeError, ValueError):
            pass
    prefix = folder.split("-", 1)[0]
    try:
        return int(prefix)
    except ValueError:
        return 10**9


def lang_label(lang: str | None) -> str:
    if not lang:
        return "Unknown"
    return LANG_LABELS.get(lang, lang)


def parse_percentile(raw) -> float | None:
    if raw is None:
        return None
    if isinstance(raw, (int, float)):
        return float(raw)
    text = str(raw).strip().rstrip("%")
    try:
        return float(text)
    except ValueError:
        return None


def percentile_index(raw) -> int | None:
    value = parse_percentile(raw)
    if value is None:
        return None
    return 9 if value >= 100 else min(9, max(0, int(value // 10)))


def percentile_label(index: int) -> str:
    start = index * 10
    return f"{start}-{start + 10}"


def percentile_buckets(problems: list[dict], field: str) -> list[tuple[str, int]]:
    counts = [0] * 10
    for problem in problems:
        index = percentile_index(problem.get(field))
        if index is None:
            continue
        counts[index] += 1
    return [(percentile_label(index), count) for index, count in enumerate(counts)]


def percentile_pages(problems: list[dict], field: str, _kind: str) -> list[tuple[str, str, int]]:
    pages = []
    for _index, (label, count) in enumerate(percentile_buckets(problems, field)):
        if count:
            pages.append((label, label, count))
    return pages


def filter_by_percentile(problems: list[dict], field: str, index: int) -> list[dict]:
    return [
        problem
        for problem in problems
        if percentile_index(problem.get(field)) == index
    ]


def runtime_percentile_buckets(problems: list[dict]) -> list[tuple[str, int]]:
    return percentile_buckets(problems, "runtimePercentile")


def memory_percentile_buckets(problems: list[dict]) -> list[tuple[str, int]]:
    return percentile_buckets(problems, "memoryPercentile")
