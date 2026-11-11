#!/bin/bash
set -e   # 명령이 하나라도 실패하면 즉시 종료

if [ $# -ne 2 ]; then
    echo "사용법: $0 <주차> <번호>" >&2
    exit 1
fi

week=$(printf "%02d" "$((10#$1))")   # 3 → 03, 03 → 03
num="$2"

src="WEEK${week}/week${week}_${num}.cpp"
out="out/week${week}_${num}"

if [ ! -f "$src" ]; then
    echo "파일이 없습니다: $src" >&2
    exit 1
fi

mkdir -p out
g++ -o "$out" "$src"
echo "----------------------------------------"
echo "컴파일 완료: $out"
echo "----------------------------------------"
echo ""

"./$out"