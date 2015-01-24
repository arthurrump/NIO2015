NIO2015
=======

Mijn oplossingen voor de opgaves van de eerste ronde van de Nederlandse Informatica Olympiade 2015 (informaticaolympiade.nl). De opgaven zijn te vinden op http://informaticaolympiade.nl/images/nio_2014_2015/Opgaven_1e_ronde_Nederlandse_Informatica_Olympiade_2014_2015_v2.pdf

Opgaves A & C
=============
Dit zijn de oplossingen zoals ik ze heb ingestuurd. De oplossingen voor A1 t/m A4 haalden de maximale score. A5 kreeg 20 punten, de helft. De oplossing voor opgave C1 bleek achteraf niet te werken met een score van 0 punten. De voorbeeldopgave ging wel goed. Opgave C2 heb ik niet gemaakt.

Opgave D: CaptureGo
===================
Het programma voor opgave D (codecup CaptureGo) kreeg 66 punten en werd 18e in de competitie. Het is een vrij slecht programma dat eerst controleert of de tegenstander een steen heeft die bijna ingesloten is. Een bijna ingesloten groep stenen wordt niet herkend. Vervolgens wordt op dezelfde manier gecontroleerd of het programma zelf bijna af is. Indien dit beide niet het geval is zet het programma direct naast z'n eigen laatste zet. Als dat ook niet kan zet hij naast de vorige zet van de tegenstander, maar alleen als hij dan niet bijna ingesloten is. Als dat niet kan probeert hij het een plaats verderop, totdat hij bij de muur is. Als er dan nog geen zet gedaan is probeert het programma een willekeurige zet.