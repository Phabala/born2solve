# 📚 born2solve - 42경산 알고리즘 스터디

하루에 한 문제씩 꾸준히 알고리즘 문제를 풀고, 서로 성장하는 스터디입니다.

## 🌱 참여 방법

- 평일 최소 **1문제**를 풀거나, 풀기 위해 노력한 문제 풀이 내용을 이 저장소에 업로드합니다.
- 문제를 풀지 않았거나 업로드하지 않으면 벌금 **1000원**을 냅니다.

## 🗂️ 폴더 구조

```
born2solve/
├── README.md
├── template.md
├── gihokim/
│   ├── 250413.md
│   └── 250414.md
├── yerpark/
│   ├── 250413.md
│   └── 250414.md
...
```

- 각자 자기 닉네임으로 폴더를 만들고, 그 폴더 안에 문제 풀이를 업로드합니다.

## ✍️ 파일 작성법

- 파일 이름: `YYMMDD.md` (예: `250414.md`)
- 파일 내용: template.md 내용을 복사/붙여넣기 해서 작성
- 작성 예시:

```markdown
**닉네임**: gihokim

**문제 플랫폼**: 백준

**문제 이름 또는 번호**: 1000 / A+B 문제

**문제 링크**: https://www.acmicpc.net/problem/1000

**오늘의 메모(선택)**: 입출력 처리에서 조금 헷갈렸음.

**코드(선택)**:

```c++
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}
\```

```

## 📝 Git 커밋 컨벤션

- 커밋 제목: `nickname: yymmdd 플랫폼 문제이름`

```bash
git commit -m "gihokim: 250414 백준 A+B"
git commit -m "yerpark: 250415 리트코드 Longest Substring Without Repeating Characters"
```

- 커밋 본문은 각자 자유롭게 적어도 좋습니다.
- 사정이 있어 문제를 풀지 못할 경우 빈 커밋을 생성해 제목에는 날짜와 `day-off`, 본문에는 사유를 작성합니다.

```bash
git commit --allow-empty -m "gihokim: 250429~250430 day-off" -m "사유: 가족 여행"
```

## ✅ 인증 방법

- 하루 1문제 풀이 기록을 **커밋 기록**으로 인증합니다.
- 플랫폼은 자유롭게 선택 가능합니다. (백준, 프로그래머스, 리트코드 등)

## 💬 참고사항

- 문제 풀이 내용을 공유하거나, 코드 리뷰를 원하는 경우는 자율적으로 진행합니다.
