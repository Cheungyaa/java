// 동물 클래스: 부모 클래스
class Animal {
    void sound() {
        System.out.println("동물이 소리를 낸다.");
    }
}

// 개 클래스: Animal 클래스를 상속받아 오버라이딩
class Dog extends Animal {
    @Override
    void sound() {
        System.out.println("개가 멍멍한다.");
    }
}

// 고양이 클래스: Animal 클래스를 상속받아 오버라이딩
class Cat extends Animal {
    @Override
    void sound() {
        System.out.println("고양이가 야옹야옹한다.");
    }
}


public class animals {
    public static void main(String[] args) {

        Animal myAnimal = new Animal();
        Animal myDog = new Dog();
        Animal myCat = new Cat();


        myAnimal.sound();
        myDog.sound();
        myCat.sound();
    }
}
