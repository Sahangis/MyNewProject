# **Release v1.2**

## **Aprašymas**
Čia yra programa, kuri skaičiuoja mokinių metinį įvertinimą ir surusiuoja mokinius į dvi atskiras grupes: kietekus ir vargsiukus, metinio formulė atrodo taip:

1. **Metinis** = 0.4 * **vidurkis** + 0.6 * **egzaminas** 

Kietekų sarašui pretenduoja studentai, kurių metinis įvertinimas yra didesnis arba lygus 5.

Vargšiukų saraše lieka tie studentai, kurių metinis įvertinimas yra mažesnis nei 5.

programa: saugoja duomenis vektoriuose ir atlieka skaičiavimus su objektiniu pagrindu(naudoja klases)

## **Failai**
Užduotį sudaro šie failai:
1. std.vector.version.cpp
2. Studentai.cpp
3. Studentai.h
4. Makefile

## **Instrukcijos**
Programos naudojimo gidas:

1. Programa duoda vartotojui pasirinkimą ivesti duomenis pačiam arba leisti programai sugeneruoti duomenis arba skaityti duomenis iš failo.
2. Pasirinkus ivedimo pačiam funkciją, vartotojas nusako n studentų kiekį ir pradeda vesti duomenis: vardą, pavardę, pažymius ir egzamino balą.
3. Suskaičiavus metinius rezultatus programa išspausdina studentų atsakymus duomenų ivedimo tvarka.
4. Jei pasirinkta generuoti duomenis, sugeneruoja 5 atskirus duomenu failus automatiskai su: 1000, 10000, 100000, 1000000 ir 10000000 studentų.
5. Jei ivestos netinkamos reikšmės programa prašo įvesti tą reikšmę iš naujo.
6. jei pasirinkta skaityti duomenis iš failo, programa paklausia, kurį failą skaityti, kokia strategija atlikti skaičiavimus ir tada nuskaito visus duomenis iš pasirinkto krusiokai(1000-10000000).txt failo ir išspausdina atsakymus.
7. visus duomenis programa išrykiuoja pagal mokinių metinį ivertį.

Galutinė išvada: Visi skaičiavimai buvo atlikti su tais pačiais duomenų failais, ankstesnė struct versija atrodo greitesnė nei dabartinė class versija,
tačiau optimizavimo flagai smarkiai padėjo veikimo spartai, nors greičio skirtumas tarp -01, -02 ir -03 flagų buvo mažas, skirtumas tarp jų ir orginalo buvo apie 1/3 pradinio greičio.

Veikimo sparta pagal programas: flag -03, flag -02, flag -01, no flag default.
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)


