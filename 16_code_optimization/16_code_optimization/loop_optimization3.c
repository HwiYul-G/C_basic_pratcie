/*
	loop ����

	1) �˰� �ִ� �Ϲ����� ����� �̿��϶�.
	��ǥ������ �̾߱� ���ڸ� 1���� n���� ���ϴ� �Լ��� ���� ���̴�.
	�Ϲ������� �̷��� �۾��� �Ѵ� �ڵ带 © ������
	for(int i = 1; i<=n; i++){
		sum += i;
	}
	������ ��ó�� ������ ���ϴ� �� ������ ������ ����
	sum = (n+1)*n /2; �� �����ϰ� ��Ÿ�� �� �մ�.
	�̷��� �ϸ� ���� ��� �ð��� �����ϰ� �ȴ�.

	2) ���� �� ���� �� ������
	�Ʒ� �ڵ�� Ư���� ���ڿ� 'a'��� ���ڰ� ���ԵǾ� �ִ� �� �˻��ϴ� �ڵ��̴�.
	while(*pstr){
		if(*pstr != 'a'){
			does_string_has_a = 1;
		}
		pstr++;
	}
	�� �ڵ忡�� does_string_has_a �� �� �� 1�� �Ǿ��ٸ�
	�ڿ��� �ٲ� ���� �����Ƿ� ���� ������ ������ �����Ѵ� ���� ���ǹ��� ���̴�.

	�̶� �̷� ������ break���� �־ ���� ���� �� �ְ� �Ѵٸ� 
	���ʿ��� ������ ���� �� �մ�.
	while (*pstr) {
		if (*pstr != 'a') {
			does_string_has_a = 1;
			break;
		}
		 pstr++;
	}

	3) �� �� �� �� ���� �ض�.
	�ϳ��� �������� ������ ���� 2�� �ϴ� �Ͱ� �ϳ��� �������� ������ ���� �� �� �ϰ�
	������ �� �� ���ٸ� ������ ��찡 �ξ� ȿ�����̴�.
	�ֳ��ϸ� ������ �� �� �� �� 
	�������� ���ǵ��� �´��� ���ϴ� �κп���
	�ð��� �ణ �Ҹ���� �����̴�.
	���� �ǵ����̸� ���� �� ���� �ȿ��� ���� ���� �ع����� ���� �߿��ϴ�.

	�Ʒ� �ڵ�� ���� n���� ���� 1�� ��Ʈ�� �� ���� �����ϴ� �� ���� ���α׷��̴�.
	while(n != 0){
		if(n & 1){
			one_bit++;
		}
		n>>1;
	}
	�� �ڵ�� �� ���� �Ѱ��� bit�� �˻��ϰ� ���������� shift�ؼ�
	�� �ٽ� �� �� ��Ʈ�� �˻��ϴ� ������ �ؼ�
	��������� ��� ��Ʈ�� �˻��� ���� 1�� ���� ������ ����.
	������ �츮�� C���� ��� ���� �ڷ����� ũ�Ⱑ 8bit�� ������� �˰� �ִ�.

	���� ��� char�� 1byte�� 8bit, int�� 4byte�� 32bit�̴�.
	���� ���� 1���� bit�� �˻��� �ʿ� ���� 8bit�� �Ѳ����� ��� �˻��ص� �������.
	�̶� 8bit�� �Ѳ����� ���ϸ� �ʹ� �����ϹǷ� 4bit�� ���ϴ� ���̴�.

	while(n != 0){
		if(n&1) one_bit++;
		if(n&2) one_bit++;
		if(n&4) one_bit++;
		if(n&8) one_bit++;
		n >>= 4;
	}
	�̷��� �ϸ� ���� ���� ȸ���� ���� �� �־ ������� �ð� ���� ȿ���� ���� �ȴ�.

	4) ���������� �ǵ��� 0�� ���ض�
	for(int i = 0; i<10; i++)
		printf("a");

	for(int i = 9; i != 0; i--)
		printf("a");

	���� 2���� for�� �� ������ �� ���� ����ɱ�?
	������ ū ���̴� ������ ������ ������ ���� �Ʒ��� ������ �� ������ ���ư���.
	�ֳ��ϸ� �� ������ i�� 10���� ������ ���ϰ� �ְ�
	�Ʒ��� ������ i�� 0�� �ٸ��� ���ϰ� �ִµ�
	�Ϲ������� 0�� ���ϴ� ���ɾ�� CPU���� ���� ������� �־ �� ������ �۵��� �� �ִ�.


	5) �ǵ��� ������ ���� ���
	int i;
	for (i = 1; i <= 3; i++) {
		func(i);
	}
	����
	
	func(1);
	func(2);
	func(3);
	�� ���� ������ Ǫ�� ���� �� ���� ���� �ִ�.
	���� ������ ���� ������ �ϴ� �� �� ���� �� �� ���
	for�� ��ü���� �������� �񱳸� �����Ѵ��� �ð��� ��� ������ ���� ����
	������ ���� �ʰ��� ��Ÿ�� �� �ִٸ� �� ����� ����!
*/