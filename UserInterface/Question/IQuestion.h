
/* ��� ��������� ��� ����� Question, ��� ����� ���� ��� �����, � ���������� ��������� �� ����� �����
* ����� ����������� ���������
* � ��� ������ ������ ��� �����: ����� VectorWithQuestionNotifier ���������� ����� Question, � � ������ Question ����������� ����� VectorWithQuestionNotifier
* �� �� �������, ���� ������. ����� ���� �� ������� � ������� ������ ���������� ��������������� �������, � ���������� �� � cpp, �� ����. ��� ���������. �� ��.
* ���� ���� ��������: ������� ������� ���������� ����� ��������� ��� Question, ����
* ��� ��� ��: ����� ������� �����, ������� ����� ���� ��������, �� ���� � �������� ������ ����� ����� �������� ����� classname(� ����� ������ ����� ����-������
* �������� ����� ���� � ����� ����������� classname ����� �� �������). ����� ��� ������? ��� �� ��������� ����� � ������� �������� �� ������ � ��������, �
* ������� ���� ����� ����� ����������� ���������(���� selectionlist ��� ������, ����� ������, ���� �� ����� ��������� �� ����� �� � ������ ���� ������������ ��)
*/
//����� ����� ������ ������ � ����� ���� ���������, ��� �������� � ���������������� ���������� ������(���� ������� - ��� ����� �����������, ������ ���)
//������ ��� ������ � ����� �����, ��������� ����



//
//class IQuestion
//{
//public:
//	static enum TypeOfAnswer
//	{
//		enterableByUser,
//		existing
//	};
//
//	virtual std::string question() const = 0;
//	virtual int typeOfAnswer() const = 0;
//	virtual const ClassName* objectFromSelectionList(const unsigned& index) const = 0;
//	virtual const size_t sizeOfSelectionList() const = 0;
//	template<typename T>
//	void refillSelectionList(VectorWithQuestionNotifier<T*>& selectionList) {};
//};