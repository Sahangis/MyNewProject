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

Failo nuskaitymas tesiai i vectoriu uztruko: 0.0015116 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0002658 s

kursiokai10000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 0.0151226 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0024983 s

kursiokai100000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 0.173504 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.0241753 s

kursiokai1000000.txt

Failo nuskaitymas tesiai i vectoriu uztrukso: 1.2808 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 0.242151 s

kursiokai10000000.txt

Failo nuskaitymas tesiai i vectoriu uztruko: 20.0585 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius uztruko: 2.83584 s

----------------------------------------------------------------------------------------------------------------------------
(Duomenys saugomi Listuose)

kursiokai1000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.0016823 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.0003356 s

kursiokai10000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.0239907 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.0045124 s

kursiokai100000.txt

Failo nuskaitymas tesiai i lista uztruko: 0.187777 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 0.06556 s

kursiokai1000000.txt

Failo nuskaitymas tesiai i lista uztruko: 1.64425 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 1.04956 s

kursiokai10000000.txt

Failo nuskaitymas tesiai i lista uztruko: 11.7147 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku listus uztruko: 14.2524 s

-----------------------------------------------------------------------------------------------------------------------------
(Duomenys saugomi Dequose)

kursiokai1000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.0028307 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.0007891 s

kursiokai10000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.0161605 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.007039 s

kursiokai100000.txt

Failo nuskaitymas tesiai i deqa uztruko: 0.154049 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 0.0945207 s

kursiokai1000000.txt

Failo nuskaitymas tesiai i deqa uztruko: 2.30649 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 1.24996 s

kursiokai10000000.txt

Failo nuskaitymas tesiai i deqa uztruko: 23.0705 s
Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku dequs uztruko: 14.967 s

---------------------------------------------------------------------------------------------------------------------------

Galutinė išvada:

   -Nuskaitymas greičiausiai vyksta į listus.
 
   -Išskyrimas į vargšiukus ir kietekus greičiausiai vyksta su vektoriais.
 
   -Overall greičiausias veikimas yra su Vektoriais
 
   -Overall lėčiausias veikimas yra su deqais
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
