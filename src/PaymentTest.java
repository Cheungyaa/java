abstract class Payment {
    abstract void processPayment();
    abstract void pay();
}

class Cash extends Payment {
    String account;

    void withdraw() {}

    @Override
    void processPayment() {}

    @Override
    void pay() {}
}

class CreditCard extends Payment {
    String cardNum;

    void transfer() {}

    @Override
    void processPayment() {}

    @Override
    void pay() {}
}

class Point extends Payment {
    int point;

    void check() {}

    @Override
    void processPayment() {}

    @Override
    void pay() {}
}
