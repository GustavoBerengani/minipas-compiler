#!/usr/bin/env bash
set -u

echo "=== Ambiente do MiniPas ==="
for command in gcc flex bison nasm clang llvm-config; do
    echo
    echo "[$command]"
    case "$command" in
        gcc) "$command" -v 2>&1 | tail -n 1 || true ;;
        nasm) "$command" -v 2>&1 || true ;;
        *) "$command" --version 2>&1 | head -n 1 || true ;;
    esac
done
