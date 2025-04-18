# DSC MQTT Interface

ESP8266 projekts, kas pieslēdzas DSC signalizācijas panelim caur Keybus un nosūta statusus uz MQTT brokeri, kā arī saņem komandas no Home Assistant vai citas automatizācijas sistēmas.

---

## Tastatūras UI piemērs

Zemāk redzams Home Assistant tastatūras interfeisa piemērs, kas darbojas kopā ar šo integrāciju:

![DSC tastatūras UI](homeasistant/hslovecase.png)

---

## Sistēmas prasības

- ESP8266 mikrokontrolleris (piemēram, D1 Mini)
- DSC signalizācijas panelis ar Keybus
- MQTT brokeris (piem., Mosquitto)
- PlatformIO (VSCode paplašinājums)

---

## Instalācija

1. **Klonē repozitoriju**

   Atver VSCode un klonē šo repozitoriju kā PlatformIO projektu.

2. **Sagatavo konfigurācijas failu**

   Failā `src/config_template.cpp` ir parauga iestatījumi.

   - Nokopē šo failu uz `src/config.cpp`
   - Atver `src/config.cpp` un ievadi savus datus:

     ```cpp
     const char * wifiSSID = "Tavs_WiFi";
     const char * wifiPassword = "Tava_parole";
     const char * accessCode = "1234";
     const char * mqttServer = "192.168.1.10";
     const char * mqttUsername = "mqtt";
     const char * mqttPassword = "parole";
     const int mqttPort = 1883;
     ```

   📌 **Fails `config.cpp` ir iekļauts `.gitignore` — tas netiks augšupielādēts uz GitHub.**

3. **Kompilē un augšupielādē uz ESP8266**

   PlatformIO iekš VSCode:
   - Spied **Upload** vai izmanto PlatformIO komandu logu:

     ```bash
     platformio run
     platformio upload
     ```

4. **Pārbaudi seriālajā monitorā**, vai ierīce pieslēdzas WiFi un MQTT.

---

## MQTT Topiki (nosūtīšana / saņemšana)

| Tēma | Apraksts |
|------|----------|
| `DSC/Get/Zone1 ... Zone64` | Zonēm individuāli |
| `DSC/Get/Partition1 ...`   | Partition statusi |
| `DSC/Get/Trouble`          | Traucējumu ziņojumi |
| `DSC/Get/Fire1`, ...       | Ugunsdrošības statuss |
| `DSC/Set/Partition1`       | Komandas: arm, disarm u.c. |

---

## Drošība

⚠️ **Fails `config.cpp` satur sensitīvu informāciju!**
Tas netiek saglabāts repozitorijā (`.gitignore`) un ir jāuztur lokāli.

---

## Iespējamās problēmas

- Ja WiFi nav pieejams, ierīce mēģina atkārtoti pieslēgties.
- Ja MQTT brokeris nav pieejams, tiek mēģināta atkārtota pieslēgšanās.
- Pēc daudziem neveiksmīgiem mēģinājumiem ESP automātiski restartējas.

---

## Plānotie uzlabojumi

- Web konfigurācijas saskarne (hotspot + iestatījumi)
- OTA atjaunināšana
- Sistēmas diagnostika caur MQTT

---

## Licence

Projekts izplatīts saskaņā ar GNU GPL v3 licenci.

Pamats: [taligentx/dscKeybusInterface](https://github.com/taligentx/dscKeybusInterface)

---

