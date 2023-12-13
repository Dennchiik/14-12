#include <iostream>
#include <string>

class Contact {
private:
    std::string fullName;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    Contact(const std::string& name, const std::string& home, const std::string& work,
        const std::string& mobile, const std::string& additional)
        : fullName(name), homePhone(home), workPhone(work),
        mobilePhone(mobile), additionalInfo(additional) {}

    const std::string& getFullName() const {
        return fullName;
    }

    const std::string& getHomePhone() const {
        return homePhone;
    }

    const std::string& getWorkPhone() const {
        return workPhone;
    }

    const std::string& getMobilePhone() const {
        return mobilePhone;
    }

    const std::string& getAdditionalInfo() const {
        return additionalInfo;
    }

    void setFullName(const std::string& name) {
        fullName = name;
    }

    void setHomePhone(const std::string& home) {
        homePhone = home;
    }

    void setWorkPhone(const std::string& work) {
        workPhone = work;
    }

    void setMobilePhone(const std::string& mobile) {
        mobilePhone = mobile;
    }

    void setAdditionalInfo(const std::string& additional) {
        additionalInfo = additional;
    }
};

void printContacts(Contact** contacts, int count) {
    std::cout << "Список контактов:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << "Имя: " << contacts[i]->getFullName() << std::endl;
        std::cout << "Домашний телефон: " << contacts[i]->getHomePhone() << std::endl;
        std::cout << "Рабочий телефон: " << contacts[i]->getWorkPhone() << std::endl;
        std::cout << "Мобильный телефон: " << contacts[i]->getMobilePhone() << std::endl;
        std::cout << "Дополнительная информация: " << contacts[i]->getAdditionalInfo() << std::endl;
        std::cout << "---------------------" << std::endl;
    }
}

void addContact(Contact**& contacts, int& count) {
    std::string name, home, work, mobile, additional;
    std::cout << "Введите имя: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Введите домашний телефон: ";
    std::cin >> home;
    std::cout << "Введите рабочий телефон: ";
    std::cin >> work;
    std::cout << "Введите мобильный телефон: ";
    std::cin >> mobile;
    std::cout << "Введите дополнительную информацию: ";
    std::cin.ignore();
    std::getline(std::cin, additional);

    Contact* newContact = new Contact(name, home, work, mobile, additional);

    Contact** temp = new Contact * [count + 1];
    for (int i = 0; i < count; ++i) {
        temp[i] = contacts[i];
    }
    temp[count] = newContact;

    delete[] contacts;
    contacts = temp;
    count++;

    std::cout << "Контакт успешно добавлен." << std::endl;
}

void deleteContact(Contact**& contacts, int& count) {
    if (count == 0) {
        std::cout << "Нет контактов для удаления." << std::endl;
        return;
    }

    int index;
    std::cout << "Введите номер контакта для удаления (от 1 до " << count << "): ";
    std::cin >> index;

    if (index > 0 && index <= count) {
        delete contacts[index - 1];
        for (int i = index - 1; i < count - 1; ++i) {
            contacts[i] = contacts[i + 1];
        }
        count--;
        std::cout << "Контакт успешно удален." << std::endl;
    }
    else {
        std::cout << "Некорректный номер контакта." << std::endl;
    }
}

void clearMemory(Contact**& contacts, int& count) {
    for (int i = 0; i < count; ++i) {
        delete contacts[i];
    }
    delete[] contacts;
    contacts = nullptr;
    count = 0;
}

int main() {
    Contact** contacts = nullptr;
    int count = 0;

    addContact(contacts, count);

    int choice = 0;

    while (choice != 4) {
        std::cout << "\nВыберите действие:\n"
            << "1. Вывести все контакты\n"
            << "2. Добавить контакт\n"
            << "3. Удалить контакт\n"
            << "4. Выйти\n"
            << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            printContacts(contacts, count);
            break;
        case 2:
            addContact(contacts, count);
            break;
        case 3:
            deleteContact(contacts, count);
            break;
        case 4:
            clearMemory(contacts, count);
            std::cout << "Завершение программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
            break;
        }
    }

    return 0;
}
