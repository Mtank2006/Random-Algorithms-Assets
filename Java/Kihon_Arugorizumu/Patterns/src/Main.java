import java.util.*;

public class Main {
    public static void main (String[] args) {
        Pattern pattern = new Pattern();
        int pattern_index;
        int size,times;
        try (Scanner sc = new Scanner(System.in)) {
            pattern_index = sc.nextInt();
            size = sc.nextInt();
//            times = sc.nextInt();
        }
        switch (pattern_index) {
            case 1:
                pattern.p_01(size);
                break;
            case 2:
                pattern.p_02(size);
                break;
            case 3:
                pattern.p_03(size);
                break;
            case 4:
                pattern.p_04(size);
                break;
            case 5:
                pattern.p_05(size);
                break;
            case 6:
                pattern.p_06(size);
                break;
            case 7:
                pattern.p_07(size);
                break;
            case 8:
                pattern.p_08(size);
                break;
            case 9:
                pattern.p_09(size);
                break;
            case 10:
                pattern.p_10(size);
                break;
            case 11:
                pattern.p_11(size);
                break;
            case 12:
                pattern.p_12(size);
                break;
            case 13:
                pattern.p_13(size);
                break;
            case 14:
                pattern.p_14(size);
                break;
            case 15:
                pattern.p_15(size);
                break;
            case 16:
                pattern.p_16(size);
                break;
            case 17:
                pattern.p_17(size);
                break;
            case 18:
                pattern.p_18(size);
                break;
            case 19:
                pattern.p_19(size);
                break;
            case 20:
                pattern.p_20(size);
                break;
            case 21:
                pattern.p_21(size);
                break;
            case 22:
                pattern.p_22(size);
                break;
            default:
                throw new IllegalStateException("Unexpected value: " + pattern_index);
        }
    }
}