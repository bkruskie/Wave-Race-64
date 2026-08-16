#!/usr/bin/env bash
# This script helps set up the private baserom repo for CI.
# Run this script locally, then follow the remaining instructions.

set -e

BASEROM_SRC="baserom.us.rev1.z64"
BASEROM_DST="baserom.us.z64"
SECRET_REPO_DIR="/tmp/wr64-baserom-setup"

echo "=== Wave Race 64 - Private Baserom Repo Setup ==="
echo ""

if [ ! -f "$BASEROM_SRC" ]; then
    echo "ERROR: Cannot find $BASEROM_SRC in the current directory."
    echo "Please ensure the baserom file is present."
    exit 1
fi

# Verify the ROM hash
ACTUAL_HASH=$(sha1sum "$BASEROM_SRC" | awk '{print $1}')
EXPECTED_HASH="508dfc2d4caa42b6f6de5263d0aed5e44ac7966a"

if [ "$ACTUAL_HASH" = "$EXPECTED_HASH" ]; then
    echo "OK: ROM SHA1 matches expected hash ($EXPECTED_HASH)"
else
    echo "WARNING: ROM SHA1 ($ACTUAL_HASH) does not match expected ($EXPECTED_HASH)"
    echo "This may cause build failures."
fi

# Create the temporary directory for the baserom repo
rm -rf "$SECRET_REPO_DIR"
mkdir -p "$SECRET_REPO_DIR"
cd "$SECRET_REPO_DIR"

# Copy the baserom with the expected name
cp "$(pwd)/$BASEROM_SRC" "$BASEROM_DST" 2>/dev/null || cp "$OLDPWD/$BASEROM_SRC" "$BASEROM_DST"

echo ""
echo "Created private baserom repo at: $SECRET_REPO_DIR"
echo "Contents:"
ls -la

echo ""
echo "=== Next Steps ==="
echo ""
echo "1. Create a NEW PRIVATE GitHub repository:"
echo "   - Go to: https://github.com/new"
echo "   - Name: wr64-baserom (or any name you prefer)"
echo "   - Set to PRIVATE"
echo "   - DO NOT initialize with README, .gitignore, or license"
echo ""
echo "2. Push the baserom to that repo:"
echo "   cd $SECRET_REPO_DIR"
echo "   git init"
echo "   git add baserom.us.z64"
echo "   git commit -m 'Add baserom'"
echo "   git branch -M main"
echo "   git remote add origin https://github.com/YOUR_USERNAME/wr64-baserom.git"
echo "   git push -u origin main"
echo ""
echo "3. Create a GitHub Personal Access Token (PAT):"
echo "   - Go to: https://github.com/settings/tokens"
echo "   - Generate new token (classic)"
echo "   - Select 'repo' scope"
echo ""
echo "4. Add secrets to your bkuskie/Wave-Race-64 repo:"
echo "   - Go to: https://github.com/bkruskie/Wave-Race-64/settings/secrets/actions"
echo "   - New repository secret: WR64_TOKEN = <your PAT>"
echo "   - New repository secret: WR64_REPO = YOUR_USERNAME/wr64-baserom"
echo "   - (Optional) New repository secret: DISCORD_URL = <your discord webhook>"
echo ""
echo "5. Register on decomp.dev:"
echo "   - Go to: https://decomp.dev/manage/new"
echo "   - Sign in with GitHub"
echo "   - Select bkuskie/Wave-Race-64"
echo "   - Install the decomp.dev GitHub App"
echo ""
echo "6. Re-run CI:"
echo "   Push a commit to trigger the build"
echo "   or manually run: https://github.com/bkruskie/Wave-Race-64/actions"
echo ""
echo "Once CI passes and uploads the 'us_report' artifact,"
echo "decomp.dev will pick it up automatically!"
