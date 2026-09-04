#!/usr/bin/env python3
"""Read leetcode/*/status.json and generate the repo README.md."""

from __future__ import annotations

from readme import load_problems, write_readme


def main() -> None:
    write_readme(load_problems())


if __name__ == "__main__":
    main()
