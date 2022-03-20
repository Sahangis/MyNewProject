# **Trečioji Užduotis - v0.4**

## **Aprašymas**
Čia yra programa, kuri skaičiuoja mokinių metinį įvertinimą ir surusiuoja mokinius į dvi atskiras grupes: kietekus ir vargsiukus, metinio formulė atrodo taip:

1. **Metinis** = 0.4 * **vidurkis** + 0.6 * **egzaminas** 

Kietekų sarašui pretenduoja studentai, kurių metinis įvertinimas yra didesnis arba lygus 5.
Vargšiukų saraše lieka tie studentai, kurių metinis įvertinimas yra mažesnis nei 5.

## **Failai**
Užduotį sudaro šie failai:
1. main.cpp
2. funkcijos.cpp
3. funkcijos.h

## **Instrukcijos**
Programos naudojimo gidas:

1. Programa duoda vartotojui pasirinkimą ivesti duomenis pačiam arba leisti programai sugeneruoti duomenis arba skaityti duomenis iš failo.
2. Pasirinkus ivedimo pačiam funkciją, vartotojas nusako n studentų kiekį ir pradeda vesti duomenis: vardą, pavardę, pažymius ir egzamino balą.
3. Suskaičiavus metinius rezultatus programa išspausdina studentų atsakymus duomenų ivedimo tvarka.
4. Jei pasirinkta generuoti duomenis, sugeneruoja 5 atskirus duomenu failus automatiskai su: 1000, 10000, 100000, 1000000 ir 10000000 studentų.
5. Jei ivestos netinkamos reikšmės programa prašo įvesti tą reikšmę iš naujo.
6. jei pasirinkta skaityti duomenis iš failo, programa paklausia, kurį failą skaityti ir nuskaito visus duomenis iš pasirinkto krusiokai(1000-10000000).txt failo ir išspausdina atsakymus.
7. visus duomenis programa išrykiuoja pagal mokinių metinį ivertį.

