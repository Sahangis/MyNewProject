# **Vector klasės tyrimai**

## **Aprašymas**
Custom parašyta vektoriaus biblioteka skirta ankstesniomis vX.X versijomis

## **Failai**
Užduotį sudaro šie failai:
1. std.vector.version.cpp
2. Studentai.cpp
3. Studentai.h
4. vektorius.h
5. Makefile

## **1. Veikla**

Vektorius veikia(funkcionalumo prasme) lygiai taip pat kaip reikalavo ankstesnės versijos

## **2. Efektyvumo spartos analizė**

debug mode:

Duomenu apdorojimas su std vektoriais 0.0050553 s

Duomenu apdorojimas su std vektoriais 0.0491979 s

Duomenu apdorojimas su std vektoriais 0.481461 s

Duomenu apdorojimas su std vektoriais 4.79834 s

----------------------------------------------------------------------------------------------------------------------------
Duomenu apdorojimas su mano vektoriais 0.0010747 s

Duomenu apdorojimas su mano vektoriais 0.0087669 s

Duomenu apdorojimas su mano vektoriais 0.0934631 s

Duomenu apdorojimas su mano vektoriais 1.10637 s


išvada: mano vektoriai greitesni debug mode.

Release mode:

Duomenu apdorojimas su std vektoriais 0.0005667 s

Duomenu apdorojimas su std vektoriais 0.0037652 s

Duomenu apdorojimas su std vektoriais 0.0479241 s

Duomenu apdorojimas su std vektoriais 0.510285 s

Duomenu apdorojimas su mano vektoriais 0.0005755 s

Duomenu apdorojimas su mano vektoriais 0.0037873 s

Duomenu apdorojimas su mano vektoriais 0.052748 s

Duomenu apdorojimas su mano vektoriais 0.5714 s

išvada: std vektoriai greitesni release mode.


## **3 punktas**

Naudojant mano Vektorių atminties konteineriu perskirstymas įvyko: 39 kartus

Naudojant std::vector atminties konteineriu perskirstymas įvyko: 41 kartą

išvada: mažiau perskirstymų prireikė: mano vektoriam

## **4 punktas**

išvada: panaudojus mano sukurtą vektorių programa veikė taip pat kaip su std::vektoriumi
 
---------------------------------------------------------------------------------------------------------------------------
Testavimams buvo naudojama:

   -CPU: AMD Ryzen 7 3800X 8-Core Processor (16 CPUs) ~3.9GHz
 
   -RAM: 32 Gb
 
   -SSD: 1 Tb (500 Gb x2)
