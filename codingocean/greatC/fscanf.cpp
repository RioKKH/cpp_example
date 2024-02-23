#include <stdio.h>

int main(int argc, char* argv[])
{
    // ディスクにかかれたファイルを読み込む
   
    // ファイル名を指定
    // const char* fileName = "./fprintf_data/data.txt";
    const char* fileName = "data.txt";
    // ファイルポインタを取得
    FILE* fp = fopen(fileName, "r"); // read
    if (fp == NULL) {
        printf("%sは開けませんでした\n", fileName);
        return 1;
    }

    int number = 0;
    char name[128];
    // EOFまで読み込む。EOFになるとfscanfは-1を返す
    while (fscanf(fp, "%d %s", &number, name) != EOF) {
    // while (fscanf(fp, "%d", &number) != -1) { // でもOK
        printf("%d %s\n", number, name);
    }

    fclose(fp);
    printf("正常終了\n");
    return 0;
}
