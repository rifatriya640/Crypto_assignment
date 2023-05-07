#include 
#define len 12 
main () {
    FILE *randfile, *outfile;
    int i;
    unsigned char next;
    randfile = fopen("/dev/random", "r");
    outfile = fopen("key.txt", "w");
    if ((randfile == NULL) II (outfile == NULL) ) {
    printf("File error!\n");
    for(i = 0 ; i< len ; i++){
        fscanf(randfile,%c,&next);
        fprint(outfile,%0.2X,&next);
    }
    fclose(randfile);
    fclose(outfile);
    return;
}
