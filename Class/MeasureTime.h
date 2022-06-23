class MeasureTime {
    public:
        MeasureTime(int pin, int target, int time);
        void complete();
    private:
        int pinNumber;
        int spendTime;
        int targetTime;
};