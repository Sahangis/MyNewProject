# **Release v1.0**

## **Aprašymas**
Čia yra programos, kurios skaičiuoja mokinių metinį įvertinimą ir surusiuoja mokinius į dvi atskiras grupes: kietekus ir vargsiukus, metinio formulė atrodo taip:

1. **Metinis** = 0.4 * **vidurkis** + 0.6 * **egzaminas** 

Kietekų sarašui pretenduoja studentai, kurių metinis įvertinimas yra didesnis arba lygus 5.

Vargšiukų saraše lieka tie studentai, kurių metinis įvertinimas yra mažesnis nei 5.

Programos yra analogiškos su vienu esminiu skirtumu:
  1 programa: saugoja duomenis vektoriuose
  2 programa: saugoja duomenis listuose
  3 programa: saugoja duomenis dequose

## **Failai**
Užduotį sudaro šie failai:
1. main.cpp
2. funkcijos.cpp
3. funkcijos.h
4. Makefile

## **Apie ankstesnius releasus:**

v0.1 release buvo labai preliminari versija programos, kuri galėjo tik skaičiuoti ar generuoti į consolę galutinius studentų įverčius(pagal vidurkį, arba medianą)

v0.2 release versijoje buvo pagrindinis pokytis, jog atsirado duomenų skaitymo iš failų funkcija, kuri pagrinde buvo tobulinta kitose versijose.

v0.3 release versijoje buvo pagražintas "behind the scenes" kodas, nes buvo įdėtas header failas ir išskirtos funkcijos į atskirą cpp faila,
taip pat buvo pridėtas try/catch, gebantis atpažinti ar duomenų failai egzistuoja.

v0.4 release buvo pridėti rezultatų failai, suskirstantys: kietekus ir vargšiukus studentus, kurių vidurkis >=5 ir kuriu <5

v0.5 release versijoje buvo sukurti 3 skirtingi programos variantai, naudojantys 3 skirtingus duomenų saugojimo metodus: Vektorius, Listus ir Dequs

## **Instrukcijos**
Programos naudojimo gidas:

1. Programa duoda vartotojui pasirinkimą ivesti duomenis pačiam arba leisti programai sugeneruoti duomenis arba skaityti duomenis iš failo.
2. Pasirinkus ivedimo pačiam funkciją, vartotojas nusako n studentų kiekį ir pradeda vesti duomenis: vardą, pavardę, pažymius ir egzamino balą.
3. Suskaičiavus metinius rezultatus programa išspausdina studentų atsakymus duomenų ivedimo tvarka.
4. Jei pasirinkta generuoti duomenis, sugeneruoja 5 atskirus duomenu failus automatiskai su: 1000, 10000, 100000, 1000000 ir 10000000 studentų.
5. Jei ivestos netinkamos reikšmės programa prašo įvesti tą reikšmę iš naujo.
6. jei pasirinkta skaityti duomenis iš failo, programa paklausia, kurį failą skaityti, kokia strategija atlikti skaičiavimus ir tada nuskaito visus duomenis iš pasirinkto krusiokai(1000-10000000).txt failo ir išspausdina atsakymus.
7. visus duomenis programa išrykiuoja pagal mokinių metinį ivertį.

strategija 1 - duomenys saugojami į vieną sarašą, iš kurio duomenys veliau yra perkialiami į du naujus sarašus.

strategija 2 - duomenys saugojami viename saraše, iš kurio dalis duomenų yra perkeliama į vieną naują sarašą.

## **v1.0 veikimo analizė**
---------------------------------------------------------------------------------------------------------------------------

Vector version:

---------------------------------------------------- 1 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0002934 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0022506 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0197037 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.269534 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 2.71317 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0001339 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0014184 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0097072 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.137629 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.37005 s

Vector išvada: 2 strategija spartesnė


List version:

---------------------------------------------------- 1 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0005614 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0061552 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.110122 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 1.65188 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 20.9367 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0003982 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0043745 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0833509 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.38199 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 18.1372 s

List išvada: 2 strategija spartesnė


Deque version:

---------------------------------------------------- 1 strategy ------------------------------------------------------
kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0006824 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0067419 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0773052 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 1.21884 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 15.024 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0004766 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0050355 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0530681 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.972324 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 12.4597 s

Deque išvada: 2 strategija spartesnė


Upgraded Vector version(prideta find if isskyrimuose):

---------------------------------------------------- 1 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0001835 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0022127 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.0179987 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 0.206917 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 2.08498 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0001397 s

kursiokai10000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0013618 s

kursiokai100000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.0098911 s

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 0.138639 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.50053 s


Upgraded Vector išvada: 2 strategija spartesnė

---------------------------------------------------------------------------------------------------------------------------

Galutinė išvada: Upgrades padėjo programai su pirma strategija, tačiau minimaliai palėtino antrąją strategiją.

Veikimo sparta pagal programas: 1. Upgraded Vektoriai, 2. Vektoriai, 3. Deqai, 4. Listai
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
