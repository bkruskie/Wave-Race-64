#!/usr/bin/env python3
"""Verify objdiff report format is compatible with decomp.dev"""
import json
import sys
import os

def check_local_report():
    """Check the local build/progress.json report"""
    try:
        with open('build/progress.json', 'r') as f:
            report = json.load(f)
        
        categories = report.get('categories', [])
        print(f"Local report found: {len(categories)} categories")
        
        total_funcs = 0
        for cat in categories:
            measures = cat.get('measures', {})
            funcs = measures.get('total_functions', 0)
            matched = measures.get('matched_functions', 0)
            pct = measures.get('matched_functions_percent', 0)
            total_funcs += funcs
            print(f"  {cat['id']}: {funcs} functions, {matched} matched ({pct}%)")
        
        print(f"\nTotal functions across categories: {total_funcs}")
        return True
    except FileNotFoundError:
        print("build/progress.json not found - run CI workflow first")
        return False
    except Exception as e:
        print(f"Error reading report: {e}")
        return False

def check_ci_artifact():
    """Check if CI artifact us_report exists"""
    if os.path.exists('build/us_report'):
        size = os.path.getsize('build/us_report')
        print(f"CI artifact found: build/us_report ({size} bytes)")
        return True
    else:
        print("CI artifact us_report not found - run workflow")
        return False

if __name__ == '__main__':
    print("=" * 60)
    print("Wave Race 64 decomp.dev Integration Check")
    print("=" * 60)
    print()
    
    local = check_local_report()
    ci = check_ci_artifact()
    
    print()
    print("=" * 60)
    if local and ci:
        print("ALL SYSTEMS GO - Your repo is ready for decomp.dev!")
        print("  1. Fork decompdev/decomp.dev")
        print("  2. Add project at https://decomp.dev/manage/new")
        print("  3. Push to main and wait ~5 minutes")
        print("  4. Badges will appear at https://decomp.dev/bkruskie/Wave-Race-64")
    else:
        print("Some checks failed - see above")
    print("=" * 60)