#include <stdio.h>
#include <string.h>

int main() {
    char str[100];  // 최대 100자 입력 가능
    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin); // 공백 포함하여 문자열 입력 받기

    int length = strlen(str);

    // fgets()는 개행 문자('\n')를 포함할 수 있으므로 제거
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0'; // 개행 문자를 널 종료 문자로 대체
        length--; // 문자열 길이 조정
    }

    printf("문자열의 길이 : %d\n", length);

    // 대소문자 변환
    for (int i = 0; i < length; i++) {
        // 대문자 (A~Z) → 소문자 (a~z) 변환
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A'); // ASCII 차이만큼 더해서 변환
        }
        // 소문자 (a~z) → 대문자 (A~Z) 변환
        else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A'); // ASCII 차이만큼 빼서 변환
        }
    }

    printf("변환된 문자열 : %s\n", str);

    return 0;
}
