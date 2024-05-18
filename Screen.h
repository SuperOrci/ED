class Screen(){
  private:
  void (*content)() = nullptr;
  void (*on_update)() = nullptr;
  public:
  void draw(){
    content();
  }
  void update(){
    on_update();
  }
}
