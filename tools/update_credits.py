#!/usr/bin/env python3
"""Fetch the contributor list of the original Wave Race 64 decomp repo and
update the CREDITORS section of README.md.

Usage: python3 tools/update_credits.py
"""

import datetime
import json
import re
import sys
import urllib.request

README = "README.md"
REPO = "LLONSIT/Wave-Race-64"
API_URL = f"https://api.github.com/repos/{REPO}/contributors?per_page=100"
BEGIN = "<!-- CREDITORS:BEGIN -->"
END = "<!-- CREDITORS:END -->"


def fetch_contributors():
    req = urllib.request.Request(API_URL, headers={"User-Agent": "update_credits"})
    with urllib.request.urlopen(req, timeout=30) as resp:
        return json.load(resp)


def build_section(contributors):
    lines = []
    lines.append("## Credits")
    lines.append("")
    lines.append(
        f"This repository is a continuation of the original decompilation by "
        f"[LLONSIT](https://github.com/LLONSIT/{REPO.split('/')[1]}), whose work this "
        f"project is built on. Credit for the original tooling, structure, and "
        f"decompilation effort goes to the project's contributors "
        f"(list generated on {datetime.date.today().isoformat()}):"
    )
    lines.append("")
    for c in contributors:
        lines.append(
            f"- [{c['login']}]({c['html_url']}) ({c['contributions']} contributions)"
        )
    lines.append("")
    lines.append(
        "Run `python3 tools/update_credits.py` to refresh this list from GitHub."
    )
    lines.append("")
    return "\n".join(lines)


def main():
    try:
        contributors = fetch_contributors()
    except Exception as e:
        print(f"error: could not fetch contributors from GitHub: {e}", file=sys.stderr)
        sys.exit(1)

    section = build_section(contributors)
    block = f"{BEGIN}\n{section}\n{END}"

    with open(README, encoding="utf-8") as f:
        text = f.read()

    if BEGIN in text and END in text:
        text = re.sub(
            re.escape(BEGIN) + r".*?" + re.escape(END),
            block,
            text,
            flags=re.S,
        )
    else:
        text = text + "\n" + block + "\n"

    with open(README, "w", encoding="utf-8", newline="\n") as f:
        f.write(text)

    print(f"updated CREDITORS section with {len(contributors)} contributors")


if __name__ == "__main__":
    main()
