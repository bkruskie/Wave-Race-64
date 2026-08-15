import json
with open('build/progress.json') as f:
    d = json.load(f)
cats = d['categories']
for c in cats:
    measures = c['measures']
    t = measures.get('total_functions', measures.get('total', 'N/A'))
    print(c['id'] + ': ' + str(t))
us = [c for c in cats if c['id'] == 'us'][0]
print('us category: ' + str(us['measures']['total_functions']) + ' functions')
print('Badge total: 1365')
funcs = sum(c['measures'].get('total_functions',0) for c in cats)
diff = 1365 - funcs
print('Difference: ' + str(diff))