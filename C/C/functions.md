
Algorithm 1

        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt++;

Algorithm 2

        int cnt = 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cnt += (i + j);
        }


Algorithm 3

        int cnt = 0
        for (int i = 0; i < n; i++) {
            while (i < n) {
                cnt++
                i++;
            }
        }

Algorithm 4

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cnt++;
            }
        }


Algorithm 5

        int i = 0, j = n;
        while (i < j) {
            i++;
            j--;
            printf("Hello, world!\n");
        }

