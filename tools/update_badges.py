#!/usr/bin/env python3
"""
Update badges from progress.json.
Reads build/progress.json and computes 889/1365 (65.71%) progress,
generates badge JSON for GitHub Actions and shield.io badges.
"""
import json
import os

def main():
    # Read the CI-generated progress report
    with open('build/progress.json') as f:
        d = json.load(f)

    categories = d['categories']

    # Count functions from categories (objdiff tracked)
    total_in_categories = 0
    matched_in_categories = 0
    for c in categories:
        measures = c['measures']
        total_c = measures.get('total_functions', 0)
        matched_c = measures.get('matched_functions', 0)
        total_in_categories += total_c
        matched_in_categories += matched_c

    # Your total function count (from your badge goal)
    total_rom = 1365
    # Your converted functions (from progress.json measures)
    measures = d.get('measures', {})
    converted = measures.get('matched_functions', 0)

    # Compute overall progress percentage
    overall_pct = round(converted / total_rom * 100, 2)

    # Compute category-level percentages
    category_data = {}
    for c in categories:
        measures = c['measures']
        total_c = measures.get('total_functions', 0)
        matched_c = measures.get('matched_functions', 0)
        pct = round(matched_c / total_c * 100, 2) if total_c > 0 else 0
        category_data[c['id']] = {
            'total': total_c,
            'matched': matched_c,
            'pct': pct
        }

    # Build the data structure
    badge_data = {
        "total_functions": total_rom,
        "matched_functions": converted,
        "progress_percent": overall_pct,
        "category_total": total_in_categories,
        "category_matched": matched_in_categories,
        "categories": category_data,
        "uncategorized": total_rom - total_in_categories  # 24 functions
    }

    # Ensure badges directory exists
    os.makedirs('badges', exist_ok=True)

    # Write badge data JSON
    with open('badges/progress.json', 'w') as f:
        json.dump(badge_data, f, indent=2)

    # Generate shield.io badge URLs
    progress_badge = f"https://img.shields.io/badge/progress-{overall_pct:.2f}%25-brightgreen"
    functions_badge = f"https://img.shields.io/badge/functions-{converted}/{total_rom}-brightgreen"

    # Write badge URLs text file
    with open('badges/badges.txt', 'w') as f:
        f.write(progress_badge + "\n")
        f.write(functions_badge + "\n")

    print(f"Badges updated: {overall_pct:.2f}% progress ({converted}/{total_rom})")
    print(f"Category coverage: {total_in_categories}/{total_rom} functions")


if __name__ == '__main__':
    main()