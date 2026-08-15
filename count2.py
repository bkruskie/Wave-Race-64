import json
with open('build/progress.json') as f:
    d = json.load(f)
cats = d['categories']
for c in cats:
    measures = c['measures']
    t = measures.get('total_functions', measures.get('total', 'N/A'))
    print(f"{c['id']}: {t}")
us = [c for c in cats if c['id'] == 'us'][0]
print(f'us category: {us[\"measures\"][\"total_functions\"]} functions')
print(f'Badge total: 1365')
diff = 1365 - sum(c['measures'].get('total_functions',0) for c in cats)
print(f'Difference: {diff}')