package com.api.crud.controller;

@RestController
@RequestMapping("/api")
public class UsuarioController{

    @Autowired
    private UsuarioService usuarioService;

    @PostMapping("/create/{nome}")
    public Usuario getCreate(@PathVariable("nome")String nome){
        return usuarioService.findGetCreate(nome);
    }

    @GetMapping("/read")
    public Usuario getReadAll(){
        return usuarioService.findGetReadAll();
    }
    
    @PutMapping("/update/{cpf}")
    public Usuario getUpdate(@PathVariable("cpf")String cpf){
        return usuarioService.findPutUser(cpf);
        
    @DeleteMapping("/delete/{cpf}")
    public Usuairo getDelete(@PathVariable("cpf)String cpf){
        return usuarioService.findDeleteUser(cpf);
    

}
