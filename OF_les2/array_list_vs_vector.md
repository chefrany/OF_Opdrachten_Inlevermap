Het verschil tussen ArrayList & Vector
============


###Research op het web
Ik ben op het internet gaan kijken naar wat de verschillen zijn tussen deze twee. Ik heb voor deze aanpak gekozen omdat ik persoonlijk echt niet wist wat het verschil zou moeten wezen tussen deze twee. Het eerste wat in mij opkwam was dat vector iets is wat je ook in illustrator hebt en tot zover ging mijn kennis en naast dat wist ik dat dit er niet mee bedoeld werd. 

### Meerdere sites met uitleg
Ik vond meerdere websites waarop ze uitgebreid uitlegde wat nou de verschillen zijn tussen deze twee. 
De ene site had een grotere uitleg dan de ander maar allemaal kwamen ze wel met elkaar over een.
Wel moet ik toegeven dat ik het niet direct begreep na de eerste keer lezen dit heeft te maken met het feit dat ik niet veel ervaring heb met deze twee dingen. 


### synchronisatie
ArrayList is niet gesynchroniseerd wat inhoud dat het meerdere taken tegelijk kan uitvoeren.

Vector is wel gesynchroniseerd wat inhoudt dat het maar een taak tegelijk kan uitvoeren.

### vergroten en verkleinen
Beide kunnen ze vergroten en verkleinen maar de wijze waarop dit gebeurd verschilt. Een ArrayList vergroot zichzelf met met 50 procent bij elke stap. 
En een Vector verdubbelt zijn grote als het vergroot wordt. 

### Prestatie
Een ArrayList kan betere prestatie leveren dan een Vector. Dit heeft te maken met het feit dat het meerdere taken tegelijkertijd kan behandelen omdat het zoals eerder verteld niet gesynchroniseerd is.

De Vector heeft een Thread safe.
Dit houdt in dat er een lock op komt zodra het bezig is met het uitvoeren van een taak wat inhoudt dat de volgende taak moet wachten voordat de ander klaar is. 

## Wanneer gebruik je Vector en wanneer ArrayList?
**Vector** kan je het best gebruiken op het moment dat er gepresteerd moet worden. Juist omdat het een Thread safe heeft is het minder gevoelig voor mogelijke errors. 

**Arraylist** kan je het beste gebruiken als het gaat om prestatie.Juist omdat het meerdere taken tegelijk kan uitvoeren.


**Bronvermelding**
[ArrayList_vs_Vector](http://beginnersbook.com/2013/12/difference-between-arraylist-and-vector-in-java/)

Gemaakt door: Chefrany Augustinus **IAD2A**