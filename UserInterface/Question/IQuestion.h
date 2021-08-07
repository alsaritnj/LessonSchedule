
/* Ёто интерфейс дл€ класс Question, все очень тупо тут будет, € задолбалс€ топтатьс€ на одном месте
* ѕќ“ќћ ќЅя«ј“≈Ћ№Ќќ ѕ≈–≈ƒ≈Ћј…
* а вот почему вообще его делаю: класс VectorWithQuestionNotifier включаетс€ класс Question, а в классе Question включаетьс€ класс VectorWithQuestionNotifier
* ну да класнно, лови ошибку. ћожно было бы сделать в хедерах просто оглавление соответствующих классов, а подключать их в cpp, но соси. там темплейты. ну ок.
* норм идеи наверное: —ƒ≈Ћј“№ –≈јЋ№Ќќ Ќќ–ћјЋ№Ќџ… ЅЋя“№ »Ќ“≈–‘≈…— ƒЋя Question, даун
* еще кое че: можно сделать класс, который будет типо стрингом, но токо в середину текста можно будет вставить класс classname(и через методы этогй убер-строки
* говорить какие пол€ в каких экземпл€рах classname стоит бы вывести). «ачем эта параша? „то бы разделить класс с обычным вопросом от класса с вопросом, в
* котором есть выбор между несколькими объектами(типо selectionlist вс€ параша, думай дальше, если ты тупой дегенерат не пон€л ну и можешь мен€ поненавидедб да)
*/
//ебать бл€ть пиздец короче в пизду этот интерфейс, тут проблема с переопределением шаблонного метода(если коротко - оно бл€ть невозмножно, потому что)
//сделаю крч просто в одном файле, переделай плиз



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