#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * f;
    char c, a, b, d[20], postava, hrdina[20], o, game;
    char e[20]="Havran";
    int i, slovo1, arr[40], sucet=0;
    for (i=0;i<20;i++){
        d[i]=NULL;
    }
    if ((f=fopen("sign.txt", "r"))==NULL){
        printf("subor sa nepodarilo otvorit\n");
    }
    printf("***********Vitajte v hre************\n");
    printf("myslite ze mozeme zacat?[Y/N]>\n");
    scanf("%c", &c);
    if (c=='Y'||c=='y'){
        printf("Nas pribeh sa odohrava v zemi Arcania, ktorej lud je na urovni stredovekej spolocnosti. Je to zem");
        printf("Kuziel, magie, nadprirodzenych bytosti a ludovych hrdinov. Casy su tazke a zivot nelahky.");
        printf("V tom case jeden mladik menom Geralt, povodom z malej dedinky zvanej Moria putoval");
        printf("krajinami a spoznaval zivot. Jedneho dna ked bol Geralt v hospode nedaleko mestecka Glasholt");
        printf(", zapocul ako sa nejaky dedincania rozpravaju, ze nedaleka provincia je suzovana neobvyklymi silami.");
        printf("Rozhodni co dalej [s-Hrdina sa opytal rolnikov na cestu, k-Hrdina sa rozhodol ostat v krcme]\n");
        scanf("%c", &a);
    }
    else if (c=='n' || c=='N'){
        printf("Tak nic\n");
    }
    scanf("%c", &a);
    if (a=='s' || a=='S'){
            printf("jeden z rolnikov mu nakreslil na kus svojho habu mapu. Bola uz polnoc a Geralt sa vydal po polnej ceste");
            printf(" zahalenej hmlou. Ked tu zrazu zapocul kvilenie vlkov. \"to nic nieje\" pomyslel si a pokracoval dalej.");
            printf(" Cesta trvala dlho a bola ako bez konca. Geralt zacal pochybovat o tom ci ide spravne. Ked uz sa chcel otocit,");
            printf(" zjavila sa pred nim stara chatrc. Vyzera opustene a tak k nej Geralt podisiel. Ked sa obzrel okolo seba ");
            printf("kutikom oka spozoroval cosi na zemi. Bola to kopka kamenov. \"zvlastne\" pomyslel si a zacal premyslat ako dalej.\n");
            printf("[d-Hrdina vosiel do chatky/i-Hrdina sa rozhodol vysetrit kamene/o-Hrdina sa rozhodol odist]\n");
            scanf("%c", &b);
            scanf("%c", &b);
                if (b=='d' || b=='D'){
                    printf("Geralt sa rozhodol pristupit ku dveram chaty. Pokusil sa otvorit si dvere, no tie sa ani nepohly. Na ");
                    printf("dverach bolo cosi vyryte: ");
                    printf("\"Dusa cierna ako tien,\"\n");
                    printf("\"meno vsetkych mien.\"\n");
                    printf("\"Ked sepkat zacne les,\"\n");
                    printf("\"do ukrytu rychlo vlez.\"\n");
                    printf("*Alister Corvinus*\n");
                    printf("\"Rebus pomyslel si hrdina\"\n");
                    printf("Odpoved?>\n");
                    scanf("%s", d);
                    slovo1=strcmp(e,d);
                    if (slovo1==0){
                        printf("\"Havran\", povedal hrdina. Alister Corvinus bol nekromant, znamy pod prezyvkou Havran. Zvlastne");
                        printf(", pomyslel si. Je mozne, ze Alister sa stal spojencom cernoknaznika Astriedaxa,o ktorom koluju zvesti v tychto ");
                        printf("koncinach? Bola hlboka noc. Mesacne nebo svietilo nad Geraltovou hlavou. Aj napriek tomu, ze hrdina ");
                        printf("poodhalil tajomstvo chtrce sa zdalo, ze sa nic nedeje. Ked v tom ucitil Geralt silnu bolest na spodnej ");
                        printf("strane svojich predlakti. Zhrozene sa zadival na svoje ruky a uvidel na nich cervene symboly. ");
                        printf("V tom cosi zacul, takmer okamzite sa obzrel. V hmle uvidel obrys postavy muza. Geralt musel ucinit ");
                        printf("rozhodnutie co dalej. \n");
                        printf("[u-utiect/p-pristupit k postave]\n");
                        scanf("%c", &postava);
                        scanf("%c", &postava);
                        if (postava=='u' || postava=='U'){
                            printf("Geralt sa rozhodol pre utek. Rozbehol sa po ceste ktorou prisiel. Citil ako ho neznama postava sleduje.");
                            printf(" Bezal a bezal az sa zrazu ocitol na krizovatke vedla, ktorej bola drevena znacka. Znacka ukazovala ");
                            printf("smer k provincii Brookden. Geralt si vydychol a este o to viac, ze neznama postava ho prestala prenasledovat.");
                            printf("****************END OF CHAPTER ONE****************");
                            while ((o=getc(f))!=EOF){
                                putchar(o);
                            }
                        }
                    }
                    else{
                        printf("Nespravne\n");
                    }
                    }
        }
        if(a=='k'|| a=='K'){
        printf("Hans popijal svoje dobre vychladene pivo premyslajuc co robit so svojim zivotom. Zrazu zbadal o kusok dalej ");
        printf("hazardnu hru s kockami. \"Mohol by som to skusit\", pomyslel si, ale na druhu stranu vedel ze hazard moze skodit ");
        printf("princip hry bol jednoduchy, hadzalo sa 3 kockami a ak bol sucet hodenych cisel vacsi alebo rovny ako 13 hrac ziskal cenu.\n");
        printf("[h-Hrat/b-dat si este pivo]");
        scanf("%c", &game);
        scanf("%c", &game);
            if(game=='h'||game=='H'){
                srand(time(NULL));
                    for (i=0; i<3; i++){
                        arr[i] = rand()%6 + 1;
                        sucet=sucet+arr[i];
                        printf("%d", arr[i]);
                    }
                printf("Sucet cisel: %d", sucet);
            }
        }
    if (fclose(f) != NULL){
        printf("subor nejde zatvorit\n");
    }
    return 0;
}
