#include <stdexcept>
#include <iostream>
#include <string>

class ConfigLoader {
    public: 
        void load(std::string filename) {

            // Fehlerfall 1: Leerer Dateiname
            if (filename.empty()) {
                throw std::invalid_argument("Dateiname darf nicht leer sein!");
            }

            // Fehlerfall 2: Falsche Dateiendung
            if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".cfg") {
                throw std::invalid_argument("Nur .cfg Dateien sind erlaubt!");
            }

            // Fehlerfall 3: Datei kann nicht geöffnet werden
            if (filename == "missing.cfg") {
                throw std::runtime_error("Datei konnte nicht geöffnet werden!");
            }

            // Fehlerfall 4: Fehlerhafte Konfiguration
            if (filename == "invalid.cfg") {
                throw std::runtime_error("Systemspezifische Konfiguration ist fehlerhaft!");
            }

            std::cout << "Datei erfolgreich geladen: " << filename << std::endl;
        }
};

int main() {
    ConfigLoader loader;

    // Testfall 1: Leerer Dateiname
    try {
        loader.load("");
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Fehler: " << e.what() << std::endl;
    }

    // Testfall 2: Falsche Endung
    try {
        loader.load("config.txt");
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Fehler: " << e.what() << std::endl;
    }

    // Testfall 3: Datei nicht gefunden
    try {
        loader.load("missing.cfg");
    }
    catch (const std::runtime_error& e) {
        std::cout << "Fehler: " << e.what() << std::endl;
    }

    // Testfall 4: Fehlerhafte Konfiguration
    try {
        loader.load("invalid.cfg");
    }
    catch (const std::runtime_error& e) {
        std::cout << "Fehler: " << e.what() << std::endl;
    }

    // Testfall 5: Erfolgreicher Fall
    try {
        loader.load("config.cfg");
    }
    catch (const std::exception& e) {
        std::cout << "Fehler: " << e.what() << std::endl;
    }

    return 0;
}