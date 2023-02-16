#include <iostream>

////// честно стыренная конвертилка для подсчета длины бордера
////// https://stackoverflow.com/questions/10846953/c-substring-multi-byte-characters/34940745#34940745

int lengthForBeauty(std::string originalString)
{
    int len = originalString.length();
    int count = 0;
    size_t origSize = originalString.size();

    for (int byteIndex=0; byteIndex < origSize; byteIndex++){
        if((originalString[byteIndex] & 0xc0) == 0x80) {
            count +=1;
        }
            
    }
    return len - count/2;
}

/*

Название:   decorator/wrapper (декоратор/обертка)
Тип:        структурирующий
Назначение: динамически добавляет объекту новые обязанности
            является гибкой альтернативой порождению подклассов
            с целью расширения функциональности
            
*/

/*************************************/
/* базовый интерфейс для компонентов */
/*************************************/

class BaseComponent {
  public:
    virtual ~BaseComponent(){}
    virtual std::string draw() = 0;
};

/*************************************/
/* базовый декоратор для компонентов */
/*************************************/

class Decorator : public BaseComponent {
private:
    BaseComponent *baseComponent;
public:
    Decorator(BaseComponent *component);
    ~Decorator();
    /*virtual*/
    std::string draw() {
        return baseComponent->draw();
    }
    
};

Decorator::Decorator(BaseComponent *component){
    baseComponent = component;
}

Decorator::~Decorator(){
    delete baseComponent;
}

/*********************************************************/
/* частный случай компонента, который будет обертываться */
/*********************************************************/

class TextLine: public BaseComponent {
  private:
    std::string text;
  public:
    TextLine(std::string t);
    ~TextLine(){};
    /*virtual*/
    std::string draw();
};

TextLine::TextLine(std::string t){
    text = t;
}

std::string TextLine::draw(){
    return TextLine::text;
}


/*******************/
/* добавляем рамку */
/*******************/

class BorderedDecorator : public Decorator{
private:
    wchar_t border;
    std::string setBorder(std::string value);
public:
    BorderedDecorator(BaseComponent*, wchar_t b);
    ~BorderedDecorator();
    /*virtual*/
    std::string draw();
};

BorderedDecorator::BorderedDecorator(BaseComponent* c, wchar_t b) : Decorator(c){
    border = b;
}

BorderedDecorator::~BorderedDecorator(){}

std::string BorderedDecorator::draw(){
    std::string base = Decorator::draw();
    return setBorder(base);
}

std::string BorderedDecorator::setBorder(std::string value){
    int valueSize = lengthForBeauty(value); 
    int borderSizeHorizontal = valueSize + 4; 
    std::string borderString = std::string(borderSizeHorizontal, BorderedDecorator::border);

    //todo: поизучать, как сделать компактнее
    std::string finalString = borderString;
    finalString.append("\n");
    finalString +=border;
    finalString.append(" ");\
    finalString.append(value);
    finalString.append(" ");
    finalString +=border;
    finalString.append("\n");
    finalString.append(borderString);

    return finalString;
}



/***************************/
/* добавляем блестки ✨✨✨ */
/***************************/

class SparkleDecorator : public Decorator{

public:
    SparkleDecorator(BaseComponent*c):Decorator(c){};
    ~SparkleDecorator(){};
    /*virtual*/
    std::string draw();
};

std::string SparkleDecorator::draw(){

    std::string finalString = "✨✨✨ ";
    finalString.append(Decorator::draw());
    finalString.append(" ✨✨✨");
    return finalString;
}