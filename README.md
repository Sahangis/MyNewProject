# **Penktoji Užduotis - v0.5**

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

## **Instrukcijos**
Programos naudojimo gidas:

1. Programa duoda vartotojui pasirinkimą ivesti duomenis pačiam arba leisti programai sugeneruoti duomenis arba skaityti duomenis iš failo.
2. Pasirinkus ivedimo pačiam funkciją, vartotojas nusako n studentų kiekį ir pradeda vesti duomenis: vardą, pavardę, pažymius ir egzamino balą.
3. Suskaičiavus metinius rezultatus programa išspausdina studentų atsakymus duomenų ivedimo tvarka.
4. Jei pasirinkta generuoti duomenis, sugeneruoja 5 atskirus duomenu failus automatiskai su: 1000, 10000, 100000, 1000000 ir 10000000 studentų.
5. Jei ivestos netinkamos reikšmės programa prašo įvesti tą reikšmę iš naujo.
6. jei pasirinkta skaityti duomenis iš failo, programa paklausia, kurį failą skaityti ir nuskaito visus duomenis iš pasirinkto krusiokai(1000-10000000).txt failo ir išspausdina atsakymus.
7. visus duomenis programa išrykiuoja pagal mokinių metinį ivertį.

## **Analizė**
(Duomenys saugomi Vektoriuose)

kursiokai1000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 0.0016519 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0002871 s

kursiokai10000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 0.0201648 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0023306 s


kursiokai100000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 0.127467 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0225131 s


kursiokai1000000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 1.53155 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.284957 s


kursiokai10000000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 17.737 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 2.63837 s


----------------------------------------------------------------------------------------------------------------------------
(Duomenys saugomi Listuose)

kursiokai1000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.0018339 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.0003953 s

kursiokai10000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.0208536 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.0039927 s

kursiokai100000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.133481 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.0658433 s

kursiokai1000000.txt

Failo nuskaitymas tesiai i lista uztruko: 1.63848 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 1.09838 s

kursiokai10000000.txt

Failo nuskaitymas tesiai i lista uztruko: 18.3833 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 14.7948 s

-----------------------------------------------------------------------------------------------------------------------------
(Duomenys saugomi Dequose)

kursiokai1000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.0017827 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.0007094 s

kursiokai10000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.0209871 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.0077866 s


kursiokai100000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.138935 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.0923417 s

kursiokai1000000.txt

Failo nuskaitymas tesiai i deqa uztruko: 1.61191 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 1.27831 s

kursiokai10000000.txt

Failo nuskaitymas tesiai i deqa uztruko: 18.4775 s

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 15.3049 s

---------------------------------------------------------------------------------------------------------------------------

Galutinė išvada:

   -Nuskaitymas greičiausiai vyksta į vektorius.
 
   -Išskyrimas į vargšiukus ir kietekus greičiausiai vyksta su vektoriais.
 
   -Overall greičiausias veikimas yra su Vektoriais
 
   -Overall lėčiausias veikimas yra su deqais
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
