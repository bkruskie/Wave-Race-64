import json
with open('build/progress.json') as f:
    d = json.load(f)
units = d.get('units', [])
print(f'Total units in report: {len(units)}')
for u in units[:3]:
    name = u.get('name', 'N/A')
    measures = u.get('measures', {})
    tf = measures.get('total_functions', 'N/A')
    print(f'  {name}: {tf} functions')
# Total from categories
cats = d.get('categories', [])
total_funcs = sum(c['measures'].get('total_functions',0) for c in cats)
print(f'\\nTotal from categories: {total_funcs}')
print(f'\\nDifference: {1365 - total_funcs}')