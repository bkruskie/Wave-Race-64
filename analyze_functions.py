#!/usr/bin/env python3
"""Analyze function counts from progress report"""
import json

with open('build/progress.json') as f:
    d = json.load(f)

print("=" * 60)
print("FUNCTION COUNTS BY CATEGORY")
print("=" * 60)

total = 0
for cat in d['categories']:
    measures = cat['measures']
    func_id = cat['id']
    total_funcs = measures['total_functions']
    matched_funcs = measures['matched_functions']
    pct = measures['matched_functions_percent']
    total += total_funcs
    print(f"{func_id:15s}: {total_funcs:3d} total, {matched_funcs:3d} matched ({pct:6.2f}%)")

print()
print("=" * 60)
print(f"Sum of categories: {total}")
print(f"Expected from badge: 1365")
print(f"Difference: {1365 - total}")
print()

# Show the "us" category details
print("=" * 60)
print("DETAIL: 'us' CATEGORY (likely has missing functions)")
print("=" * 60)
us_cat = None
for cat in d['categories']:
    if cat['id'] == 'us':
        us_cat = cat
        break

if us_cat:
    measures = us_cat['measures']
    print(f"Total functions: {measures['total_functions']}")
    print(f"Matched functions: {measures['matched_functions']}")
    print(f"Match percent: {measures['matched_functions_percent']}")
    print(f"Total code: {measures['total_code']}")
    print(f"Matched code: {measures['matched_code']}")
    print(f"Matched code percent: {measures['matched_code_percent']}")
    
    # Show progress_categories
    print(f"\nProgress categories: {us_cat.get('progress_categories', [])}")
else:
    print("'us' category not found")