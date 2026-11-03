#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 30
#define LINE_LEN 256

enum { OK = 0, BAD_OPERATOR, BAD_NUMBER };

/* 공백 건너뛰기 */
static const char *skip_spaces(const char *p) {
    while (*p == ' ' || *p == '\t')
        p++;
    return p;
}

/* p에서 숫자를 읽어 out에 저장. 최대 MAX_DIGITS 자리 */
static const char *read_number(const char *p, char *out, int *status) {
    int len = 0;
    while (*p >= '0' && *p <= '9') {
        if (len == MAX_DIGITS) {
            *status = BAD_NUMBER;
            return p;
        }
        out[len++] = *p++;
    }
    out[len] = '\0';
    if (len == 0)
        *status = BAD_NUMBER;
    return p;
}

/* "A + B" 형식 파싱 */
static int parse(const char *line, char *a, char *b) {
    int status = OK;
    const char *p = skip_spaces(line);

    p = read_number(p, a, &status);
    if (status != OK) return status;

    p = skip_spaces(p);
    if (*p != '+') return BAD_OPERATOR;
    p = skip_spaces(p + 1);

    p = read_number(p, b, &status);
    if (status != OK) return status;

    p = skip_spaces(p);
    if (*p != '\n' && *p != '\0') return BAD_OPERATOR;
    return OK;
}

/* 앞자리 0 제거 */
static const char *strip_zeros(const char *s) {
    while (*s == '0' && s[1] != '\0')
        s++;
    return s;
}

/* 오른쪽 자리부터 더하기. 결과가 MAX_DIGITS 자리를 넘으면 -1 */
static int add_numbers(const char *a, const char *b, char *result) {
    char tmp[MAX_DIGITS + 2];
    int i = (int)strlen(a) - 1, j = (int)strlen(b) - 1, k = 0, carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int d = carry;
        if (i >= 0) d += a[i--] - '0';
        if (j >= 0) d += b[j--] - '0';
        tmp[k++] = (char)(d % 10 + '0');
        carry = d / 10;
    }
    if (k > MAX_DIGITS)
        return -1;
    for (int n = 0; n < k; n++)
        result[n] = tmp[k - 1 - n];
    result[k] = '\0';
    return 0;
}

/* 세 자리마다 쉼표 */
static void print_with_commas(const char *s) {
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++) {
        putchar(s[i]);
        if ((len - i - 1) % 3 == 0 && i < len - 1)
            putchar(',');
    }
    putchar('\n');
}

static int ask_again(void) {
    char line[LINE_LEN];
    for (;;) {
        printf("계속 하시겠습니까? ");
        if (!fgets(line, sizeof line, stdin))
            return 0;
        if (line[0] == 'y') return 1;
        if (line[0] == 'n') return 0;
    }
}

int main(void) {
    char line[LINE_LEN];
    char a[MAX_DIGITS + 1], b[MAX_DIGITS + 1], sum[MAX_DIGITS + 1];

    do {
        printf("수식 : ");
        if (!fgets(line, sizeof line, stdin))
            break;

        switch (parse(line, a, b)) {
        case BAD_OPERATOR:
            printf("결과 : 잘못된 연산자입니다.\n");
            break;
        case BAD_NUMBER:
            printf("결과 : 30자리 이하의 숫자를 입력하세요.\n");
            break;
        default:
            if (add_numbers(strip_zeros(a), strip_zeros(b), sum) != 0) {
                printf("오버플로우가 발생했습니다.\n");
            } else {
                printf("결과 : ");
                print_with_commas(sum);
            }
        }
        printf("\n");
    } while (ask_again());

    return 0;
}
