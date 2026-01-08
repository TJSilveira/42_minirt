#!/bin/bash
passed=0
failed=0

for file in test_import/*; do
  printf "Running .rt test files %-40s ... " "$(basename "$file")"

  # Capture stderr, discard stdout
  err=$(./bin/minirt "$file" 2>&1)
  if echo "$err" | grep -q "^Error.*"; then
    echo "PASS"
    passed=$((passed+1))
  else
    echo "FAIL"
    failed=$((failed+1))
    if [ -n "$err" ]; then
      echo "  Stderr:"
      echo "$err" | sed 's/^/    /' | head -n 5
    else
      echo "  Stderr: (empty)"
    fi
  fi
done

printf "Running test on now existing file                               ... "
err=$(./bin/minirt "doesnotexist.rt" 2>&1)
if echo "$err" | grep -q "^Error.*"; then
  echo "PASS"
  passed=$((passed+1))
else
  echo "FAIL"
  failed=$((failed+1))
  if [ -n "$err" ]; then
    echo "  Stderr:"
    echo "$err" | sed 's/^/    /' | head -n 5
  else
    echo "  Stderr: (empty)"
  fi
fi

echo
echo "Summary: PASS=$passed  FAIL=$failed  TOTAL=$((passed+failed))"
