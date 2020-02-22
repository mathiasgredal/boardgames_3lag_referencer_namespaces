# Boardgames lister

Forrige projekt: [Skak](https://bitbucket.org/jacs_zbc/projekt-skak/src/master/)

Generel feedback:

- Alle gruppemedlemmer skal angives på forside af synopsis
- Henvis til alle skabeloner/kodestumper (også selvom de er udleveret)
- Link til repo med kildekode (master branch skal være den "færdige" udgave)
- Husk også brugertest
- Brug logbog undervejs til noter (og sørg for at repos er løbende opdateret)

## Vigtige begreber

- 3-lagsarkitektur (Se [afsnit](https://informatik.systime.dk/index.php?id=1124) i informatik bog.)
- Funktionsparametre som værdier vs referencer
- Namespaces

---

### Funktionsparametre som værdier eller referencer

```c++
int a = 10;
int b = a;          // Kopi
int& c = a;         // Reference (kan ændre a)
const int& d = a;   // Konstant reference (kan ikke ændre a)
```

#### Pass-by-value

Ved vores sædvanlige angivelse af funktionsparametre oprettes en kopi af værdien i funktionen. Nedenunder kopieres variablen `x`:

```c++
int fun(int x){
    return x + 1;
}
```

#### Pass-by-const-reference

Det kan være dyrt (hukommelse/tid) at oprette en af kopi af store variabler, fx en `vector` med mange elementer. I stedet kan man angive funktionsparameteren som en konstant (`const`) reference `&`. Her oprettes ikke en lokal kopi, men variablen kan stadig læses i funktionen, dog kan den ikke ændres (hvilket er med til at forhindre fejl).

```c++
void print(const vector<int>& x){
    for(int k = 0; k < x.size(); k++){
        cout << x[k] << endl;
    }
}
```

#### Pass-by-reference

Nogle gange vil vi også gerne kunne modificere referencen (fx når en stor `vector` skal ændres). I de tilfælde kan vi bare undlade den konstante `const` del fra før. Begræns dog så vidt muligt brugen af ikke-konstante referencer, da der hurtigere opstår fejl.

```c++
void init(vector<int>& x){
    for(int k = 0; k < x.size(); k++){
        x[k] = k;
    }
}
```

#### Hvornår bruges hvilken type af funktionsparametre

- Brug kopiering for små variabler.
- Brug konstante reference for store variabler som ikke skal modificeres.
- Returnér så vidt muligt et resultat fremfor at modificere en reference.

### Namespaces (kommer senere)

---

## Opgaver

Brug kildekoden i dette repo som udgangspunkt eller lav din egen udgave som følger 3-lagsarkitekturen. Programmet skal kunne læse en liste med brætspil og tilhørende data fra filen `top100bgg.csv`, foretage forskellige former for sortering og præsentere resultaterne for brugeren.

1. Sæt dig ind i:
    - [Kommasepareret filtype](https://en.wikipedia.org/wiki/Comma-separated_values#Example) (.csv)
    - [3-lagsarkitektur](https://informatik.systime.dk/index.php?id=1124)
    - Kildekoden i oplægget (hvis du bruger den)

2. Læs resten af opgaverne igennem (uden at lave dem) og gennemgå derefter nedenstående punkter.
    - Indskriv de forskellige dele af det forventede færdige program i 3-lagsarkitekturen.
    - Lav et flowdiagram eller pseudokode til minimum en af de dele som du senere skal implementere.
    - Lav minimum 2 tomme funktionsstubbe til funktioner som du regner med at få brug for senere (Mañana-princippet). Husk at placere dem korrekt i kildekoden i forhold til 3-lagsarkitekturen.

3. Lav en funktion der kan vise alle spil på listen. Funktionsparameteren skal bruge pass-by-const-reference.

4. Opdatér funktionen der læser data fra en fil, således at alle informationer (Board Game Rank; Title; Geek Rating; Avg Rating; Num Voters) bliver gemt i hver deres `vector` variabel vha. pass-by-reference. Udskriv "Avg Rating" sammen med titlen for hvert spil.

5. Lav to funktioner der kan vende om på rækkefølgen i en `vector<string>` der angives som parameteren (uden brug af `reverse` fra STL). Fx skal `anders, rip, rap, rup` blive til `rup, rap , rip, anders`.
    - Den ene funktion skal producere en ny `vector` med den nye rækkefølge, så den gamle `vector` bevares.
    - Den anden funktion skal direkte lave om på rækkefølgen uden brug af andre `vectors`, fx vha. [swap()](http://www.cplusplus.com/reference/algorithm/swap/)
    - Afprøv begge funktioner på listen med brætspil.

6. I ratingsystemer med brugerstemmer bruges ofte [Bayesiansk gennemsnit](https://en.wikipedia.org/wiki/Bayesian_average) for at undgå at elementer med meget få stemmer bliver over- eller undervurderet. En modificeret version af dette er brugt til at beregne "Geek Rating" i datasættet.
    - Opret en funktion der vha. lister med "avg rating" og "Num Voters" som funktionsparametre udregner et Bayesiansk gennemsnit hvor C = 2000 og m = 5.5. Brug formlen i linket ovenfor som udgangspunkt. Funktionen skal returnere en ny liste med de Bayesianske gennemsnit.
    - Sammenlign resultatet med "Geek Rating".

7. Lav en funktion der beregner den maximale og minimale værdi i en liste samt gennemsnittet og medianen (brug [sort()](http://www.cplusplus.com/reference/algorithm/sort/) til at sørge for at input er sorteret før median beregnes). Returner resultaterne vha. referencer eller vha. en brugerdefineret klasse. Afprøv funktionen på "Geek Rating".

8. Lav en funktion der har `vector<string>` som parameter og returnerer en liste med antallet af bogstaver i hver titel. Find også den længste og korteste streng, evt. vha. funktionen fra sidste opgave.

9. I denne opgave skal der sorteres. Man skal implementere sin egen version af en sorteringsalgoritme (hvoraf der findes mange, se fx [[1](https://www.youtube.com/watch?v=kPRA0W1kECg)][[2](https://www.youtube.com/watch?v=lyZQPjUT5B4)][[3](https://www.youtube.com/watch?v=ywWBy6J5gz8)][[4](https://www.youtube.com/watch?v=XaqR3G_NVoo)]) og man kan sammenligne med [sort()](http://www.cplusplus.com/reference/algorithm/sort/).
    - Implementer en eller flere sorteringsalgoritmer med udgangspunkt i deres flowdiagrammer. Brug algoritmerne til at sortere listen med "Avg Rating" så den højeste værdi er på index 0. Nedenfor er en liste med forslag i stigende sværhedsgrad - modstå fristelsen til at se på løsninger før du selv har prøvet.
        - Selection Sort: [wiki](https://en.wikipedia.org/wiki/Selection_sort) + [rutediagram](images/selection_sort.svg)
        - Bubble Sort: [wiki](https://en.wikipedia.org/wiki/Bubble_sort) + [rutediagram](images/bubble_sort.svg)
        - Merge Sort: [wiki](https://en.wikipedia.org/wiki/Merge_sort) + [rutediagram](images/merge_sort.svg)
        - Quicksort: [wiki](https://en.wikipedia.org/wiki/Quicksort) + [rutediagram](images/Quicksort.svg)
    - Sørg derefter for at listen med brætspil bliver sorteret i samme rækkefølge som "Avg Rating" er blevet sorteret og udskriv resultatet (evt. kun de `n` bedste eller værste).
    - Test hvor lang tid det tager for dine algoritmer at sortere en liste og hvor lang tid det tager for `sort()` (se evt. [næste afsnit](#kodeeksempel-timing-af-sort)). Overvej hvilke af ovenstående algoritmer der kræver mest hukommelse.

10. Gennemgå din kode for de tidligere opgaver.
    - Omstrukturer koden hvor det ville gøre koden pænere eller nemmere at forstå.
    - Opret kontrol af input og output i dine funktioner vha. `assert` og/eller `try/catch`). Fx kan der være krav til typen af tal, at flere lister skal have samme størrelse eller andet.

---

## Kodeeksempel: Timing af sort()

```c++
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

int main()
{
    srand(high_resolution_clock::now().time_since_epoch().count());
    rand();
    int N = 1000000;
    vector<float> test(N,0);
    for(int k = 0; k < N; k++){
        test[k] = rand();
    }
    vector<float> test2 = test;
    auto start_time = high_resolution_clock::now();
    sort(test.begin(),test.end());
    duration<float> dur = chrono::system_clock::now()-start_time;
    cout << "Sort took: " << dur.count() << " seconds" << endl;
}
```
