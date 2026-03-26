import static java.lang.Math.*;
public class Pattern {
    public void p_01(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_02(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = n; j > i; j--) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_03(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print(j+1);
            }
            System.out.println();
        }
    }
    public void p_04(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print(i+1);
            }
            System.out.println();
        }
    }
    public void p_05(int n) {
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_06(int n) {
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print(j+1);
            }
            System.out.println();
        }
    }
    public void p_07(int n) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n -i-1; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < (2*i)+1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_08(int n) {
        for (int i = n; i > 0; i--) {
            for (int k = 0; k < n -i; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < (2*i)-1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_09(int n) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n -i-1; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < (2*i)+1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = n; i > 0; i--) {
            for (int k = 0; k < n -i; k++) {
                System.out.print(" ");
            }
            for (int j = 0; j < (2*i)-1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
    public void p_10(int n) {
        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = n-1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
    public void p_11(int n) {
        byte temp = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i+1; j++) {
                System.out.print(temp);
                if (temp == 1){
                    temp = 0;
                }
                else temp = 1;
            }
            System.out.println();
            if (i%2 == 1) {
                temp = 1;
            }
        }
    }
    public void p_12(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print(j+1);
            }
            for (int j = 0; j < 2*(n-i-1); j++) {
                System.out.print(" ");
            }
            for (int j = i + 1; j > 0; j--) {
                System.out.print(j);
            }
            System.out.println();
        }
    }
    public void p_13(int n) {
        byte temp = 1; //temp range is -128 to 127
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i+1; j++) {
                System.out.print(temp+" ");
                temp++;
            }
            System.out.println();
        }
    }
    public void p_14(int n) {
        for (int i = 0; i < n; i++) {
            byte temp = 65; //temp range is -128 to 127
            for (int j = 0; j < i+1; j++) {
                char c = (char)temp;
                System.out.print(c);
                temp++;
            }
            System.out.println();
        }
    }
    public void p_15(int n) {
        for (int i = n; i > 0; i--) {
            byte temp = 65; //temp range is -128 to 127
            for (int j = 0; j < i; j++) {
                char c = (char)temp;
                System.out.print(c);
                temp++;
            }
            System.out.println();
        }
    }
    public void p_16(int n) {
        byte temp = 65; //temp range is -128 to 127
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i+1; j++) {
                char c = (char)temp;
                System.out.print(c);
            }
            temp++;
            System.out.println();
        }
    }
    public void p_17(int n) {
        for (int i = 0; i < n; i++) {
            byte temp = 65; //temp range is -128 to 127
            for (int j = 0; j < n -i-1; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < i+1; j++) {
                char c = (char)temp;
                System.out.print(c);
                temp++;
            }
            temp -=2;
            for (int j = i; j > 0; j--) {
                char c = (char)temp;
                System.out.print(c);
                temp--;
            }
            System.out.println();
        }
    }
    public void p_18(int n) {
        for (int i = 0; i < n; i++) {
            int temp = 65+n;
            temp -= (i+1);
            for (int j = 0; j < i+1; j++) {
                char c = (char)temp;
                System.out.print(c);
                temp++;
            }
            System.out.println();
        }
    }
    public void p_19(int n) {
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            for (int j = n-i; j > 0; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            for (int j = n-i; j > 0; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
    public void p_20(int n) {
        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            for (int j = n-i; j > 0; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print("*");
            }
            System.out.println();
        }
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            for (int j = n-i; j > 0; j--) {
                System.out.print(" ");
            }
            for (int j = 0; j < n-i; j++) {
                System.out.print(" ");
            }
            for (int j = i; j > 0; j--) {
                System.out.print("*");
            }
            System.out.println();
        }

    }
    public void p_21(int n) {
        for (int i = 0; i < n; i++) {
            if ( i==0 || i==n-1) {
                for (int j = 0; j < n; j++) {
                    System.out.print("*");
                }
            }
            else {
                System.out.print("*");
                for (int j = 1; j < n-1; j++) {
                    System.out.print(" ");
                }
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public void p_22(int n) {
        for (int i = 0; i < (2*n)-1; i++) {
            for (int j = 0; j <(2*n)-1; j++) {
                System.out.print(max(abs(i - n + 1),abs(j - n + 1))+1 + " ");
            }
            System.out.println();
        }
    }
}