package com.api.crud.model;

import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

import lombok.Data;

@Data
@Document(collection = "Usuario")
public class Usuario {

    @Id
    private String cpf;
    
    private String nome;
    
    


}
