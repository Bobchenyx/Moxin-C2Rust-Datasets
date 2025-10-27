#define MAX(a,b) ((a) > (b) ? (a) :(b))
#define MIN(a,b) ((a) < (b) ? (a) :(b))

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
    int overlap_area = 0;
    int area = 0;

    if(!(E >= C|| F >= D || G <= A | H <= B))
    {
        int x1 = MAX(A,E);
        int x2 = MIN(C,G);
        int y1 = MAX(F,B);
        int y2 = MIN(D,H);

        overlap_area = (x2 - x1) * (y2 - y1);
    }

    int area1 = (C - A) * (D - B);
    int area2 = (G - E) * (H -F );


    return area1 + (area2 - overlap_area);
}