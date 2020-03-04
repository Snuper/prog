FILE *fp2= fopen("result.txt","w");
fprintf(fp2, "Количество правильных ответов: ");
fprintf(fp2, "%d", otvet);
fclose(fp2);

