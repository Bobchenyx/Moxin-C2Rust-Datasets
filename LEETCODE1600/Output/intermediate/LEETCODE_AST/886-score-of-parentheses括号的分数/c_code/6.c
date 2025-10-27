int GetScore(char **S)
{
    int score = 0;
    while (**S != '\0') {
        if (**S == '(') {
            *S += 1;
            score += GetScore(S);
        } else {
            *S += 1;
            score *= 2;
            return (score == 0) ? 1 : score;
        }
    }
    return score;
}
int scoreOfParentheses(char *S)
{
    return GetScore(&S);
}