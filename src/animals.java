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

// 메인 클래스: 실행용
public class animals {
    public static void main(String[] args) {
        // 부모 타입으로 자식 객체를 다룰 수 있다 → 다형성!
        Animal myAnimal = new Animal();
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        // 각각의 sound() 호출 → 오버라이딩된 메서드가 실행됨
        myAnimal.sound();  // 출력: 동물이 소리를 낸다.
        myDog.sound();     // 출력: 개가 멍멍한다.
        myCat.sound();     // 출력: 고양이가 야옹야옹한다.
    }
}
