#include <iostream>
#include <string>

class Researcher {
    public:
        Researcher(std:: string, std::string, std::string, float, float);
        void displayName();
        virtual void thesis();
    protected:
        std::string area;
        float word_count;
        float words;
        int will_to_live;
    private:
        std::string name;
        std::string title;
};

Researcher::Researcher(std::string newName, std::string newTitle, std::string thesis_area, float thesis_word_count, float thesis_words) {
    name = newName;
    title = newTitle;
    area = thesis_area;
    word_count = thesis_word_count;
    words = thesis_words;
}

void Researcher::displayName(){
    std::cout << "Title: " << title << std::endl;
    std::cout << "Name: " << name << std::endl;
}

void Researcher::thesis() {
    int progress = (words/word_count)*100;
    std::cout << "Thesis on " << area << ". " << progress << "% out of " << word_count << " words written." << std::endl;
}

class MPhilStudent : public Researcher {
    public:
        MPhilStudent(std::string newName, std::string newTitle, std::string thesis_area, float thesis_word_count, float thesis_words) : Researcher(newName, newTitle, thesis_area, thesis_word_count, thesis_words) {}
};

class PhDStudent : public Researcher {
    public:
        PhDStudent(std::string newName, std::string newTitle, std::string thesis_area, float thesis_word_count, float thesis_words) : Researcher(newName, newTitle, thesis_area, thesis_word_count, thesis_words) {}
        void set_will_to_live(int will) {
            will_to_live = will;
        }
        void show_will_to_live(int will) {
            std::cout << "Will to live: " << will << std::endl;
        }
};

class PostDoc : public Researcher {
    public:
        PostDoc(std::string newName, std::string newTitle, std::string thesis_area) : Researcher(newName, newTitle, thesis_area, 0, 0) {}
        void thesis() override;
};

void PostDoc::thesis() {
    std::cout << "Thesis on " << area << " was done a long time ago!" << std::endl;
}

int main() {
    Researcher dv = Researcher("Darth Vader", "Lord", "Deathstars", 100, 90);
    dv.displayName();
    MPhilStudent me = MPhilStudent("James Hughes", "Mr", "Something Fun", 7000, 78);
    me.thesis();
    PostDoc js = PostDoc("John Smith", "Baron", "Enothelial-micro-mycology");
    js.thesis();
}