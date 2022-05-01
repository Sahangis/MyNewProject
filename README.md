# **Release v1.1**

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

strategija 1 - duomenys saugojami į vieną sarašą, iš kurio duomenys veliau yra perkialiami į du naujus sarašus.

strategija 2 - duomenys saugojami viename saraše, iš kurio dalis duomenų yra perkeliama į vieną naują sarašą.

## **v1.1 veikimo analizė**
---------------------------------------------------------------------------------------------------------------------------

Vector version default make (no flags):

---------------------------------------------------- 1 strategy ------------------------------------------------------

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 3.255 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 58.7458 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 3.11569 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 57.2822 s

Vector išvada: 2 strategija spartesnė

-----------------------------------------------------------------------------------------------------------------------

Old Vector default version with structs:

---------------------------------------------------- 1 strategy ------------------------------------------------------

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 1.97944 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 1 strategija uztruko: 24.1647 s

---------------------------------------------------- 2 strategy ------------------------------------------------------

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.94525 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 22.9408 s

List išvada: old struct vector version spartesnė abejomis strategijomis

----------------------------------------------------------------------------------------------------------------------

**Flagų testavimam naudojama 2 strategija kuri spartesnė**

Make version with flag -01 :

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.67053 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 39.6206 s

-----------------------------------------------------------------------------------------------------------------------

Make version with flag -02 :

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.64859 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 38.112 s

-------------------------------------------------------------------------------------------------------------------------
Make version with flag -03 :

kursiokai1000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 1.63881 s

kursiokai10000000.txt

Duomenu isrykiavimas ir isskyrimas i du atskirus kieteku, ir vargsiuku vectorius pagal 2 strategija uztruko: 38.0752 s

---------------------------------------------------------------------------------------------------------------------------

Galutinė išvada: Visi skaičiavimai buvo atlikti su tais pačiais duomenų failais, ankstesnė struct versija atrodo greitesnė nei dabartinė class versija,
tačiau optimizavimo flagai smarkiai padėjo veikimo spartai, nors greičio skirtumas tarp -01, -02 ir -03 flagų buvo mažas, skirtumas tarp jų ir orginalo buvo apie 1/3 pradinio greičio.

Veikimo sparta pagal programas: flag -03, flag -02, flag -01, no flag default.
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
