from datetime import timedelta, timezone
from pathlib import Path

TAIPEI_TZ = timezone(timedelta(hours=8))

ROOT = Path(__file__).resolve().parents[2]
LEETCODE_DIR = ROOT / "leetcode"
ASSETS_DIR = ROOT / "assets"
STATS_DIR = ROOT / "stats"
DIFFICULTY_DIR = STATS_DIR / "difficulty"
LANGUAGES_DIR = STATS_DIR / "languages"
RUNTIME_DIR = STATS_DIR / "runtime"
MEMORY_DIR = STATS_DIR / "memory"
TOPICS_DIR = STATS_DIR / "topics"
README_PATH = ROOT / "README.md"
SITE_TITLE = "LeetCode Tracker"

LEETCODE_USERNAME = "f964966828"
STATS_CARD_URL = (
    f"https://leetcard.jacoblin.cool/{LEETCODE_USERNAME}"
    "?theme=dark"
    "&font=Noto_Sans_Tai_Tham"
    "&colors=1e1e2e,45475a,cdd6f4,bac2de,fab387,a6e3a1,f9e2af,f38ba8"
    "&ext=contest"
    "&site=us"
)
PROFILE_URL = f"https://leetcode.com/{LEETCODE_USERNAME}"
RECENT_LIMIT = 100
TOPICS_CHART_LIMIT = 10
TOPICS_LINK_COLUMNS = 4

LANG_LABELS = {
    "c": "C",
    "cpp": "C++",
    "csharp": "C#",
    "golang": "Go",
    "java": "Java",
    "javascript": "JavaScript",
    "kotlin": "Kotlin",
    "mssql": "SQL",
    "mysql": "SQL",
    "oraclesql": "SQL",
    "php": "PHP",
    "postgresql": "SQL",
    "python": "Python",
    "python3": "Python",
    "pythondata": "Python",
    "ruby": "Ruby",
    "rust": "Rust",
    "scala": "Scala",
    "swift": "Swift",
    "typescript": "TypeScript",
}

PAGE_SLUGS = {
    "Easy": "easy",
    "Medium": "medium",
    "Hard": "hard",
    "Unknown": "unknown",
    "C++": "cpp",
    "C#": "csharp",
    "C": "c",
    "Go": "go",
    "Java": "java",
    "JavaScript": "javascript",
    "Kotlin": "kotlin",
    "SQL": "sql",
    "PHP": "php",
    "Python": "python",
    "Ruby": "ruby",
    "Rust": "rust",
    "Scala": "scala",
    "Swift": "swift",
    "TypeScript": "typescript",
    "Shell": "shell",
}

DIFFICULTY_ORDER = ("Easy", "Medium", "Hard")
DIFFICULTY_COLORS = {
    "Easy": "#a6e3a1",
    "Medium": "#f9e2af",
    "Hard": "#f38ba8",
    "Unknown": "#bac2de",
}
CHART_PALETTE = (
    "#fab387",
    "#a6e3a1",
    "#89b4fa",
    "#f9e2af",
    "#cba6f7",
    "#f38ba8",
    "#94e2d5",
    "#74c7ec",
)
CHART_BG = "#1e1e2e"
CHART_SURFACE = "#181825"
CHART_BORDER = "#313244"
CHART_TEXT = "#cdd6f4"
CHART_MUTED = "#a6adc8"
CHART_TRACK = "#313244"
CHART_FONT = "ui-sans-serif, system-ui, Segoe UI, sans-serif"
CHART_MONO = "ui-monospace, SFMono-Regular, Menlo, Consolas, monospace"
