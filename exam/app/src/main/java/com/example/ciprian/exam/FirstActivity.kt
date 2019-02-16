package com.example.ciprian.exam

import android.arch.lifecycle.Observer
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.support.design.widget.Snackbar
import android.support.v7.widget.LinearLayoutManager
import android.support.v7.widget.RecyclerView
import android.view.View
import android.widget.Toast
import com.example.ciprian.exam.adapters.MainAdapter
import kotlinx.android.synthetic.main.activity_first.*

class FirstActivity : AppCompatActivity(),MyCallback {
    var adapter: MainAdapter? = null

    private var recyclerView: View? = null
    private var manager: Manager? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_first)

        add_button.setOnClickListener{
            val intent = Intent(this,NewActivity::class.java)
            startActivityForResult(intent,1001)
        }
        users_button.setOnClickListener{
//            if(manager!!.networkConnectivity(applicationContext)){
//                Toast.makeText(applicationContext,"Not available offline", Toast.LENGTH_SHORT).show()
//            }else{
                val intent = Intent(this, ThirdActivity::class.java)
                startActivityForResult(intent, 1000)
            //}

        }
        manager = Manager(application as MyApp)
        recyclerView = findViewById(R.id.public_list)
        setupRecyclerView(recyclerView as RecyclerView)
        loadEvents()
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        loadEvents()
    }

    fun loadEvents():Boolean{
        progressFirst.visibility = View.VISIBLE
        val connectivity = manager!!.networkConnectivity(applicationContext)
        if(!connectivity){
            showError("There is no connection")
        } else{
            manager!!.loadPublic(progressFirst,this,this)
        }

        return connectivity
    }
    override fun clear() {

    }

    override fun showError(message: String) {
        progressFirst.visibility = View.GONE
        Snackbar.make(recyclerView!!, message, Snackbar.LENGTH_INDEFINITE)
                .setAction("RETRY") { loadEvents() }.show()
    }

//    private fun setupRecyclerView(recyclerView: RecyclerView){
//        adapter = MainAdapter()
////        (application as MyApp).db.typeDao.types
////                .observe(this, Observer { bikes ->
////                    if (bikes != null) {
////                        //adapter!!.setData(bikes as MutableList<Type>,progressFirst,application as RateApp,this,this)
////                    }
////                })
//
//        recyclerView.layoutManager = LinearLayoutManager(this)
//        recyclerView.adapter = adapter
//    }

    private fun setupRecyclerView(recyclerView: RecyclerView){
        adapter = MainAdapter()

        recyclerView.layoutManager = LinearLayoutManager(this)
        recyclerView.adapter = adapter
    }
}
