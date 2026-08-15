#!/usr/bin/env python3
import json
with open('build/progress.json') as f:
    d = json.load(f)
cats = d['categories']
# Print each category with its total functions
for c in cats:
    t = c['measures']['total_functions']
    print(f"{c['id']}: {t}")
# Now sum unique - check if any overlap
print(f"\nSum of all: {sum(c['measures']['total_functions'] for c in cats)}")
# Check us category specifically
us = [c for c in cats if c['id'] == 'us'][0]
print(f"\nus category: {us['measures']['total_functions']} functions")
# Total from badge
print(f"\nBadge total: 1365")
print(f"Difference: {1365 - sum(c['measures']['total_functions'] for c in cats)}")