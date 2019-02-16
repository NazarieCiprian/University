package com.example.ciprian.exam

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toast
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        section_one.setOnClickListener{
            val manager = Manager(application as MyApp)
            if(manager.networkConnectivity(application!!.applicationContext)){
                val intent = Intent(this, FirstActivity::class.java)
                startActivity(intent)
            }else{
                Toast.makeText(application!!.applicationContext, "Not allowed while offline",Toast.LENGTH_SHORT).show()
            }

        }

        section_two.setOnClickListener{
            val intent = Intent(this, SixthActivity::class.java)
            startActivity(intent)
        }
    }
}
