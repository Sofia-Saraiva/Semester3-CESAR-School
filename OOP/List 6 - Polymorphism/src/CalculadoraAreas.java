public class CalculadoraAreas {
    public static double calcularArea(float base, float altura, float angulo) {
        return base * altura;
    }

    public static double calcularArea(double lado) {
        return calcularArea((float)lado, (float)lado, 0);
    }

    public static double calcularArea(double base, double altura) {
        return calcularArea((float)base, (float)altura, 0);
    }

    public static double calcularArea(float raio) {
        return 3.14 * (raio * raio);
    }
}
